#关于集成IDFA版本app中没有广告AppStore审核问题

##### 由于Appstore禁止不使用广告而采集IDFA的app上架，LinkedME提供IDFA版和不含IDFA版两个SDK，两个SDK在功能上并没有差异，采集IDFA是为了防止今后因为苹果可能禁止目前使用的openudid,idfv而造成的数据波动。且不采集idfa无法检测广告效果

如果您的应用使用LinkedME标准SDK而未集成任何广告服务，但需要跟踪广告带来的激活行为，请按照下图填写Appstore中的IDFA选项：

![idfa](http://7xq8b0.com1.z0.glb.clouddn.com/idfa.png)

-------

✓1.serve advertisements within the app
服务应用中的广告。如果你的应用中集成了广告的时候，你需要勾选这一项。


✓2.Attribute this app installation to a previously served advertisement.
跟踪广告带来的安装。

✓3.Attribute an action taken within this app to a previously served advertisement
跟踪广告带来的用户的后续行为。

✓4.Limit Ad Tracking setting in iOS
这一项下的内容其实就是对你的应用使用idfa的目的做下确认，只要你选择了采集idfa，那么这一项都是需要勾选的。

如果您仍因为采集IDFA被Appstore审核拒绝，建议您集成任意一家广告或选用LinkedME无IDFA版SDK。

#接入方法

##使用 CocoaPods
```
pod 'LinkedME-iOS-Deep-Linking-Demo_Pod',:git=>"https://github.com/WFC-LinkedME/LinkedME-iOS-Deep-Linking-Demo.git"
```
##手动集成
手动集成用户,去除AdSupport.frame框架即可 

![AdSupport](http://7xq8b0.com1.z0.glb.clouddn.com/adsupport.png)

