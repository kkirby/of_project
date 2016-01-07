SODIR=/Users/kkirbatski/Desktop/of_project/libs/android/armeabi-v7a
make Debug PLATFORM_VARIANT=shared PLATFORM_OS=Android -j8 && \
zip -j ${SODIR}/libOFAndroidApp.so.zip ${SODIR}/libOFAndroidApp.so && \
adb push -p ${SODIR}/libOFAndroidApp.so.zip /data/data/com.someplace.asdfasdf/lib/libOFAndroidApp.so.zip && \
adb shell am force-stop com.someplace.asdfasdf && \
adb shell unzip -o /data/data/com.someplace.asdfasdf/lib/libOFAndroidApp.so.zip -d /data/data/com.someplace.asdfasdf/lib/ && \
adb shell am start -n com.someplace.asdfasdf/com.someplace.asdf.OFActivity