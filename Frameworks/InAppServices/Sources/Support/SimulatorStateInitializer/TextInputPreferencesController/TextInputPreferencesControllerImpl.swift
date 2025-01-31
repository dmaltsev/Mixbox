#if MIXBOX_ENABLE_IN_APP_SERVICES

import MixboxFoundation
import MixboxUiKit

// Swift wrapper for private `TIPreferencesController`.
//
// Keyboard preferences are stored in
// `data/Library/Preferences/com.apple.keyboard.preferences.plist`
// on iOS 15 (and many versions prior to this)
public final class TextInputPreferencesControllerImpl: TextInputPreferencesController {
    private let tiPreferencesController: TIPreferencesControllerObjCWrapper
    private let iosVersionProvider: IosVersionProvider
    private let userInterfaceIdiomProvider: UserInterfaceIdiomProvider

    public init(
        tiPreferencesController: TIPreferencesControllerObjCWrapper,
        iosVersionProvider: IosVersionProvider,
        userInterfaceIdiomProvider: UserInterfaceIdiomProvider
    ) {
        self.tiPreferencesController = tiPreferencesController
        self.iosVersionProvider = iosVersionProvider
        self.userInterfaceIdiomProvider = userInterfaceIdiomProvider
    }
    
    public func setAutocorrectionEnabled(_ value: Bool) {
        tiPreferencesController.setAutocorrectionEnabled(value)
    }
    
    public func setPredictionEnabled(_ value: Bool) {
        tiPreferencesController.setPredictionEnabled(value)
    }
    
    public func setDidShowGestureKeyboardIntroduction(_ value: Bool) {
        guard iosVersionProvider.iosVersion().majorVersion >= 11 else {
            return
        }
        
        setPreference(
            key: "DidShowGestureKeyboardIntroduction",
            value: value
        )
    }
    
    public func setDidShowContinuousPathIntroduction(_ value: Bool) {
        guard iosVersionProvider.iosVersion().majorVersion >= 13 else {
            return
        }
        
        switch userInterfaceIdiomProvider.userInterfaceIdiom() {
        case .phone:
            setPreference(
                key: "DidShowContinuousPathIntroduction",
                value: value
            )
        case .carPlay, .mac, .pad, .tv, .unspecified:
            break
        @unknown default:
            break
        }
    }
    
    public func synchronizePreferences() {
        tiPreferencesController.synchronizePreferences()
    }
    
    private func setPreference(key: String, value: Bool) {
        tiPreferencesController.setValue(
            value as NSValue,
            forPreferenceKey: key
        )
    }
}

#endif
