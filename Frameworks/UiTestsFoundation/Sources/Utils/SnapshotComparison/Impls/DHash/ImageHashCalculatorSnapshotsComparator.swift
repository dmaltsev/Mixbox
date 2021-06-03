import UIKit

public final class ImageHashCalculatorSnapshotsComparator: SnapshotsComparator {
    private let imageHashCalculator: ImageHashCalculator
    private let hashDistanceTolerance: UInt8
    
    public init(
        imageHashCalculator: ImageHashCalculator,
        hashDistanceTolerance: UInt8)
    {
        self.imageHashCalculator = imageHashCalculator
        self.hashDistanceTolerance = hashDistanceTolerance
    }
    
    public func compare(actualImage: UIImage, expectedImage: UIImage) -> SnapshotsComparisonResult {
        return ComparisonContext(
            imageHashCalculator: imageHashCalculator,
            hashDistanceTolerance: hashDistanceTolerance,
            actualImage: actualImage,
            expectedImage: expectedImage
        ).compare()
    }
}
