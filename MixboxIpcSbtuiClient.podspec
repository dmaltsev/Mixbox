require_relative 'cocoapods/mixbox_spec'

Mixbox::FrameworkSpec.new do |s|
  s.name = 'MixboxIpcSbtuiClient'
  s.platforms = [:ios]
  
  s.dependency 'MixboxIpc'
  s.dependency 'MixboxSBTUITestTunnelClient'
  
  # for network mocks,  kind of a kludge, but SBTUITestTunnel should be removed soon:
  s.dependency 'MixboxTestsFoundation' 
  s.dependency 'MixboxUiTestsFoundation'
  
  s.framework = "XCTest"
  
  s.user_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(PLATFORM_DIR)/Developer/Library/Frameworks'
  }
  
  s.xcconfig = {
    'ENABLE_TESTING_SEARCH_PATHS' => 'YES',
    'LIBRARY_SEARCH_PATHS' => '$(TOOLCHAIN_DIR)/usr/lib/swift-$(SWIFT_VERSION)/$(PLATFORM_NAME) $(inherited)'
  }
end