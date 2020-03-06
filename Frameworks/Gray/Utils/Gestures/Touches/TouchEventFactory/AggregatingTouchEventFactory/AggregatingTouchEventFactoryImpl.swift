import MixboxFoundation
import MixboxInAppServices
import MixboxIoKit

public final class AggregatingTouchEventFactoryImpl: AggregatingTouchEventFactory {
    public func aggregatingTouchEvent(
        dequeuedMultiTouchInfo: DequeuedMultiTouchInfo,
        time: AbsoluteTime)
        -> DigitizerEvent
    {
        let event = DigitizerEvent(
            allocator: kCFAllocatorDefault,
            timeStamp: time,
            transducer: .finger,
            index: 0,
            identifier: 0,
            eventMask: eventMask(dequeuedMultiTouchInfo: dequeuedMultiTouchInfo),
            buttonEvent: 0,
            x: 0,
            y: 0,
            z: 0,
            tipPressure: 0,
            twist: 0,
            range: false,
            touch: touch(dequeuedMultiTouchInfo: dequeuedMultiTouchInfo),
            options: []
        )
        
        event.digitizer.isDisplayIntegrated = true
        
        return event
    }

    // Returns 1 for all events where the fingers are on the glass (everything but ended and canceled).
    private func touch(dequeuedMultiTouchInfo: DequeuedMultiTouchInfo) -> Bool {
        return dequeuedMultiTouchInfo.touchesByFinger.contains { touch in
            switch touch.phase {
            case .began, .moved, .stationary:
                return true
            case .ended, .cancelled:
                return false
            }
        }
    }
        
    private func eventMask(dequeuedMultiTouchInfo: DequeuedMultiTouchInfo) -> IOHIDDigitizerEventMask {
        var eventMask = IOHIDDigitizerEventMask()
        
        if maskShouldIncludeTouch(dequeuedMultiTouchInfo: dequeuedMultiTouchInfo) {
            eventMask.update(with: .touch)
        }
        
        if maskShouldIncludeAttribute(dequeuedMultiTouchInfo: dequeuedMultiTouchInfo) {
            eventMask.update(with: .attribute)
        }
        
        return eventMask
    }
    
    private func maskShouldIncludeTouch(dequeuedMultiTouchInfo: DequeuedMultiTouchInfo) -> Bool {
        // If there are any new or ended events, mask includes touch.
        return dequeuedMultiTouchInfo.touchesByFinger.contains { touch in
            switch touch.phase {
            case .began, .ended, .cancelled:
                return true
            case .moved, .stationary:
                return false
            }
        }
    }
    
    private func maskShouldIncludeAttribute(dequeuedMultiTouchInfo: DequeuedMultiTouchInfo) -> Bool {
        // If there are any pressure readings, mask must include attribute
        return dequeuedMultiTouchInfo.touchesByFinger.contains { touch in
            touch.pressure != nil
        }
    }
}