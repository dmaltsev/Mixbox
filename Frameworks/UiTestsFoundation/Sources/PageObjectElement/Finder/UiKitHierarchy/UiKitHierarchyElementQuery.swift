import MixboxFoundation
import MixboxTestsFoundation
import MixboxIpc
import MixboxIpcCommon

final class UiKitHierarchyElementQuery: ElementQuery {
    private let ipcClient: SynchronousIpcClient
    private let elementMatcher: ElementMatcher
    private let testFailureRecorder: TestFailureRecorder
    private let stepLogger: StepLogger
    private let applicationScreenshotTaker: ApplicationScreenshotTaker
    private let performanceLogger: PerformanceLogger
    private let dateProvider: DateProvider
    private let elementFunctionDeclarationLocation: FunctionDeclarationLocation
    
    init(
        ipcClient: SynchronousIpcClient,
        elementMatcher: ElementMatcher,
        testFailureRecorder: TestFailureRecorder,
        stepLogger: StepLogger,
        applicationScreenshotTaker: ApplicationScreenshotTaker,
        performanceLogger: PerformanceLogger,
        dateProvider: DateProvider,
        elementFunctionDeclarationLocation: FunctionDeclarationLocation)
    {
        self.ipcClient = ipcClient
        self.elementMatcher = elementMatcher
        self.testFailureRecorder = testFailureRecorder
        self.stepLogger = stepLogger
        self.applicationScreenshotTaker = applicationScreenshotTaker
        self.performanceLogger = performanceLogger
        self.dateProvider = dateProvider
        self.elementFunctionDeclarationLocation = elementFunctionDeclarationLocation
    }
    
    func resolveElement(interactionMode: InteractionMode) -> ResolvedElementQuery {
        return performanceLogger.logSignpost(staticName: "RVHEQ resolveElement") {
            let stepLogBefore = StepLogBefore(
                date: dateProvider.currentDate(),
                title: "Поиск элемента"
            )
            
            let wrapper = stepLogger.logStep(stepLogBefore: stepLogBefore) {
                resolveElementWhileBeingLoggedToStepLogger(interactionMode: interactionMode)
            }
            
            return wrapper.wrappedResult
        }
    }
    
    // TODO: interactionMode is unused. This will produce bugs. See XcuiElementQuery for reference.
    // TODO: Write test. There is no test for that. E.g.: trying to get element #2 from matching element should
    //       produce proper failure if there is only 1 matching element. Maybe there should be also some other logic.
    private func resolveElementWhileBeingLoggedToStepLogger(
        interactionMode: InteractionMode)
        -> StepLoggerResultWrapper<ResolvedElementQuery>
    {
        switch viewHierarchy() {
        case .data(let viewHierarchy):
            return getResolvedElementQueryWhileBeingLoggedToStepLogger(viewHierarchy: viewHierarchy)
        case .error(let error):
            return reportIpcFailedWhileGettingHierarchy(error: error)
        }
    }
    
    private func viewHierarchy()
        -> DataResult<ViewHierarchy, Error>
    {
        return performanceLogger.logSignpost(staticName: "RVHEQ viewHierarchy") {
            ipcClient.call(
                method: ViewHierarchyIpcMethod()
            )
        }
    }
    
    private func reportIpcFailedWhileGettingHierarchy(
        error: Error)
        -> StepLoggerResultWrapper<ResolvedElementQuery>
    {
        // TODO: better FileLine (should point to invocation in test)
        testFailureRecorder.recordFailure(
            description: "Не удалось получить иерархию вьюх из приложения: \(error)",
            fileLine: FileLine.current(),
            shouldContinueTest: false
        )
        
        // TODO: Get rid of ElementQueryResolvingState, it is only a kludge for XCUI
        let emptyState = ElementQueryResolvingState()
        emptyState.start()
        emptyState.stop()
        
        let emptyQuery = ResolvedElementQuery(
            elementQueryResolvingState: emptyState
        )
        
        return StepLoggerResultWrapper(
            stepLogAfter: StepLogAfter(
                date: dateProvider.currentDate(),
                wasSuccessful: false,
                attachments: []
            ),
            wrappedResult: emptyQuery
        )
    }
    
    private func getResolvedElementQueryWhileBeingLoggedToStepLogger(viewHierarchy: ViewHierarchy)
        -> StepLoggerResultWrapper<ResolvedElementQuery>
    {
        let resolvedElementQuery = performanceLogger.logSignpost(staticName: "RVHEQ resolveElementQuery") {
            resolveElementQuery(viewHierarchy: viewHierarchy)
        }
        
        return performanceLogger.logSignpost(staticName: "RVHEQ log to StepLogger") {
            log(resolvedElementQuery: resolvedElementQuery, viewHierarchy: viewHierarchy)
        }
    }
    
    private func resolveElementQuery(viewHierarchy: ViewHierarchy) -> ResolvedElementQuery {
        let elementQueryResolvingState = ElementQueryResolvingState()
        
        // We don't actually need start/stop. It is a kludge for XCUI. TODO: Get rid of it.
        elementQueryResolvingState.start()
        
        performanceLogger.logSignpost(staticName: "RVHEQ all matching") {
            for element in viewHierarchy.rootElements {
                matchRecursively(element: element, state: elementQueryResolvingState)
            }
        }
        
        elementQueryResolvingState.stop()
        
        return ResolvedElementQuery(elementQueryResolvingState: elementQueryResolvingState)
    }
    
    private func matchRecursively(
        element: ViewHierarchyElement,
        parent: ElementSnapshot? = nil,
        state: ElementQueryResolvingState)
    {
        let snapshot = UiKitHierarchyElementSnaphot(element: element, parent: parent)
        let matchingResult = performanceLogger.logSignpost(staticName: "RVHEQ elementMatcher.matches") {
            elementMatcher.match(value: snapshot)
        }
        state.append(matchingResult: matchingResult, elementSnapshot: snapshot)
        
        for child in element.children {
            matchRecursively(element: child, parent: snapshot, state: state)
        }
    }
    
    private func log(resolvedElementQuery: ResolvedElementQuery, viewHierarchy: ViewHierarchy)
        -> StepLoggerResultWrapper<ResolvedElementQuery>
    {
        let elementWasFound = !resolvedElementQuery.matchingSnapshots.isEmpty
        
        return StepLoggerResultWrapper(
            stepLogAfter: StepLogAfter(
                date: dateProvider.currentDate(),
                wasSuccessful: elementWasFound,
                attachments: attachmentsForLog(
                    resolvedElementQuery: resolvedElementQuery,
                    viewHierarchy: viewHierarchy
                )
            ),
            wrappedResult: resolvedElementQuery
        )
    }
    
    // TODO: This logic is copypasted from XcuiElementQuery. Share.
    private func attachmentsForLog(resolvedElementQuery: ResolvedElementQuery, viewHierarchy: ViewHierarchy) -> [Attachment] {
        var attachments = [Attachment]()
        
        if let candidatesDescription = resolvedElementQuery.candidatesDescription() {
            attachments.append(
                Attachment(
                    name: "Кандидаты",
                    content: .text(candidatesDescription.description)
                )
            )
            attachments.append(
                Attachment(
                    name: "Иерархия вьюх",
                    content: .text(
                        viewHierarchy.debugDescription
                    )
                )
            )
            attachments.append(
                Attachment(
                    name: "Строка и файл где объявлен локатор",
                    content: .text(
                        """
                        \(elementFunctionDeclarationLocation.fileLine.file):\(elementFunctionDeclarationLocation.fileLine.line):
                        \(elementFunctionDeclarationLocation.function)
                        """
                    )
                )
            )
            if let screenshot = try? applicationScreenshotTaker.takeApplicationScreenshot() {
                attachments.append(
                    Attachment(
                        name: "Скриншот",
                        content: .screenshot(screenshot)
                    )
                )
            }
            attachments.append(
                contentsOf: candidatesDescription.attachments
            )
        }
        
        return attachments
    }
}
