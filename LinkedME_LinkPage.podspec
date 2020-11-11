Pod::Spec.new do |s|
s.name                  = "LinkedME_LinkPage"
s.version          	= '1.5.5.4'
s.summary               = "LinkedME Deeplink"
s.description           = <<-DESC
LinkedME Deeplink for iOS.
DESC

s.homepage              = "https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo.git"
s.license               = 'MIT'
s.author                = { "Bindx" => "487479@gmail.com"}
s.source                = { :git => "https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo.git", :tag => s.version }

s.vendored_frameworks = 'LinkedME_DEMO/LinkedME_iOS.framework'


s.platform              = :ios
s.ios.deployment_target = '6.0'
s.requires_arc          = true

s.frameworks = 'SystemConfiguration','Security','CoreSpotlight','CoreLocation','AdSupport','CoreTelephony','WebKit','StoreKit','CoreLocation'

end
