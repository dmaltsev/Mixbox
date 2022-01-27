import TestDiscovery
import Foundation
import Destinations
import BuildArtifacts
import RunnerModels

public final class TestArgFileGeneratorArguments {
    public let iosBuildArtifacts: IosBuildArtifacts
    public let mixboxTestDestinationConfigurations: [MixboxTestDestinationConfiguration]
    public let environment: [String: String]
    public let priority: UInt
    
    public init(
        iosBuildArtifacts: IosBuildArtifacts,
        mixboxTestDestinationConfigurations: [MixboxTestDestinationConfiguration],
        environment: [String: String],
        priority: UInt)
    {
        self.iosBuildArtifacts = iosBuildArtifacts
        self.mixboxTestDestinationConfigurations = mixboxTestDestinationConfigurations
        self.environment = environment
        self.priority = priority
    }
}
