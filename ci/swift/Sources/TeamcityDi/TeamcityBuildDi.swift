import Dip
import Tasks
import Destinations
import CiFoundation
import SingletonHell
import Emcee
import Cocoapods
import CiDi
import Bundler
import TestRunning

public final class TeamcityBuildDi: CommonDi {
    override public func registerAll(container: DependencyContainer) {
        super.registerAll(container: container)
        
        container.register(type: LocalTaskExecutor.self) {
            TeamcityLocalTaskExecutor()
        }
        container.register(type: CocoapodsSearchOutputParser.self) {
            CocoapodsSearchOutputParserImpl()
        }
        container.register(type: RemoteCacheConfigProvider.self) {
            let environmentProvider: EnvironmentProvider = try container.resolve()
            
            return RemoteCacheConfigProviderImpl(
                fileDownloader: try container.resolve(),
                remoteCacheConfigJsonUrl: try environmentProvider.getUrlOrThrow(
                    env: Env.MIXBOX_CI_EMCEE_REMOTE_CACHE_CONFIG
                )
            )
        }
        container.register(type: DeveloperDirProvider.self) {
            let environmentProvider: EnvironmentProvider = try container.resolve()
            
            return DeveloperDirProviderImpl(
                xcodeCFBundleShortVersionString: try environmentProvider.getOrThrow(
                    env: Env.MIXBOX_CI_XCODE_VERSION
                ) 
            )
        }
        container.register(type: SimulatorSettingsProvider.self) {
            SimulatorSettingsProviderImpl(
                environmentProvider: try container.resolve()
            )
        }
        container.register(type: CocoapodsTrunkTokenProvider.self) {
            TeamcityCocoapodsTrunkTokenProvider(
                environmentProvider: try container.resolve()
            )
        }
        container.register(type: BundlerBashCommandGenerator.self) {
            BundlerBashCommandGeneratorImpl(
                gemfileLocationProvider: try container.resolve(),
                bashEscapedCommandMaker: try container.resolve(),
                bundlerToUse: .useSystem
            )
        }
        container.register(type: TestRunner.self) {
            let environmentProvider = try container.resolve() as EnvironmentProvider
            
            return try EmceeTestRunner(
                emceeProvider: container.resolve(),
                temporaryFileProvider: container.resolve(),
                bashExecutor: container.resolve(),
                queueServerRunConfigurationUrl: environmentProvider.getUrlOrThrow(
                    env: Env.MIXBOX_CI_EMCEE_QUEUE_SERVER_RUN_CONFIGURATION_URL
                ),
                testArgFileJsonGenerator: container.resolve(),
                fileDownloader: container.resolve(),
                environmentProvider: container.resolve()
            )
        }
        container.register(type: CiLogger.self) {
            TeamcityCiLogger()
        }
    }
}
