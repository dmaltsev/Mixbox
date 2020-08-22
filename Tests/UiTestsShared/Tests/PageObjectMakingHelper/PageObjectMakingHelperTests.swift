import MixboxUiTestsFoundation
import TestsIpc

final class PageObjectMakingHelperTests: TestCase {
    private var screen: IpcTestingViewPageObject {
        return pageObjects.ipcTestingView.default
    }
    
    private var outdatedView: ViewElement {
        return screen.byId("outdated_id")
    }
    
    override func precondition() {
        super.precondition()
        
        open(screen: pageObjects.ipcTestingView)
            .waitUntilViewIsLoaded()
    }
    
    override func setUp() {
        mocks.register(type: InteractionFailureDebugger.self) { di in
            InteractionFailureDebuggerImpl(
                alertDisplayer: try di.resolve(),
                pageObjectElementGenerationWizardRunner: try di.resolve()
            )
        }
        
        super.setUp()
    }
    
    func disabled_test() {
        resetUi()
        
        outdatedView.withoutTimeout.tap()
    }
    
    override func resetUi() {
        let bounds = mainScreenBounds()
        
        var frame = CGRect(
            origin: .zero,
            size: CGSize(width: 100, height: 100)
        )
        frame.mb_center = bounds.mb_center
        
        resetUi(
            argument: IpcTestingViewConfiguration(
                views: [
                    IpcView(
                        frame: frame,
                        accessibilityIdentifier: "updated_id",
                        backgroundColor: .green
                    )
                ]
            )
        )
    }
}
