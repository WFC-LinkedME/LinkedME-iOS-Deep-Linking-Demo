Pod::Spec.new do |s|
s.name                  = "LinkedME-iOS-Deep-Linking-Demo"
s.version               = ¡°1.0.1¡±
s.homepage              = "https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo"
s.license               = 'MIT'
s.author                = { "Bindx" => "487479@gmail.com"}
s.source                = { :git => "https://github.com/bindx/DXLocationManager.git", :tag => "v1.0.0" }
s.source_files          = 'LinkedME-iOS-Deep-Linking-Demo/LinkedME_DEMO/LinkedME_iOS.framework'
s.platform              = :ios
s.ios.deployment_target = '6.0'
s.requires_arc          = true
s.summary               = "DXLocation for iOS."
s.description           = <<-DESC
It is a marquee view used on iOS, which implement by Objective-C.
DESC

end