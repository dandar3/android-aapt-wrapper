Wrapper for Android AAPT tool to pass '--no-version-vectors' when packaging.

This is useful for non-Gradle builds that cannot pass this parameter (e.g. Android ADT not maintained anymore), to avoid apps using AppCompat to crash with:

```
Caused by: android.content.res.Resources$NotFoundException: File res/drawable/abc_vector_test.xml from drawable resource ID #0x7f020052
       at android.content.res.Resources.loadDrawable(Resources.java:1953)
       at android.content.res.Resources.getDrawable(Resources.java:660)
       at android.support.v7.widget.VectorEnabledTintResources.superGetDrawable(VectorEnabledTintResources.java:74)
       at android.support.v7.widget.AppCompatDrawableManager.onDrawableLoadedFromResources(AppCompatDrawableManager.java:435)
       at android.support.v7.widget.VectorEnabledTintResources.getDrawable(VectorEnabledTintResources.java:67)
       at android.support.v4.content.ContextCompat.getDrawable(ContextCompat.java:353)
       at android.support.v7.widget.AppCompatDrawableManager.getDrawable(AppCompatDrawableManager.java:200)
       at android.support.v7.widget.AppCompatDrawableManager.getDrawable(AppCompatDrawableManager.java:188)
       at android.support.v7.widget.AppCompatDrawableManager.checkVectorDrawableSetup(AppCompatDrawableManager.java:755)
       at android.support.v7.widget.AppCompatDrawableManager.getDrawable(AppCompatDrawableManager.java:193)
       at android.support.v7.widget.TintTypedArray.getDrawableIfKnown(TintTypedArray.java:87)
       at android.support.v7.app.AppCompatDelegateImplBase.<init>(AppCompatDelegateImplBase.java:128)
       at android.support.v7.app.AppCompatDelegateImplV9.<init>(AppCompatDelegateImplV9.java:149)
       at android.support.v7.app.AppCompatDelegateImplV11.<init>(AppCompatDelegateImplV11.java:29)
       at android.support.v7.app.AppCompatDelegateImplV14.<init>(AppCompatDelegateImplV14.java:54)
       at android.support.v7.app.AppCompatDelegate.create(AppCompatDelegate.java:202)
       at android.support.v7.app.AppCompatDelegate.create(AppCompatDelegate.java:183)
       at android.support.v7.app.AppCompatActivity.getDelegate(AppCompatActivity.java:519)
       at android.support.v7.app.AppCompatActivity.onCreate(AppCompatActivity.java:70)
       at com.example.googleplayservicesdemo.MainActivity.onCreate(MainActivity.java:19)
       at android.app.Activity.performCreate(Activity.java:5104)
       at android.app.Instrumentation.callActivityOnCreate(Instrumentation.java:1080)
       at android.app.ActivityThread.performLaunchActivity(ActivityThread.java:2144)
       ... 11 more
Caused by: org.xmlpull.v1.XmlPullParserException: Binary XML file line #17: invalid drawable tag vector
       at android.graphics.drawable.Drawable.createFromXmlInner(Drawable.java:881)
       at android.graphics.drawable.Drawable.createFromXml(Drawable.java:822)
       at android.content.res.Resources.loadDrawable(Resources.java:1950)
       ... 33 more
```

## References

[Android Developers - Vector Drawables Backward Compatibility Solution](https://developer.android.com/guide/topics/graphics/vector-drawable-resources.html#vector-drawables-backward-solution)

## Installation

#### Windows
* Navigate to `android-sdk\build-tools\xx.y.z\`
* Rename `aapt.exe` to `aapt-original.exe`
* Save `aapt-wrapper.exe` as `aapt.exe`

#### Unix
* Navigate to `android-sdk/build-tools/xx.y.z/`
* Rename `aapt` to `aapt-original`
* Save `aapt-wrapper` as `aapt`

## How to compile

Optional step if you need to compile it yourself.
* using [MingW](http://www.mingw.org/wiki/howto_install_the_mingw_gcc_compiler_suite) for Windows / g++ for Linux

`g++ aapt-wrapper.cpp -o aapt-wrapper`
