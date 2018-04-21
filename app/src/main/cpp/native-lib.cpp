#include <jni.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>

#include <android/log.h>
#define LOG_TAG    "TestAndroidJNI"

#ifdef __cplusplus
extern "C" {
#endif

#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)


JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_testVector(JNIEnv *env, jobject /* this */){
    std::string strTest;
    int number;

    std::vector<std::string> vector;
    vector.push_back("test1");
    vector.push_back("test2");
    vector.push_back("test3");
    vector.push_back("test4 i am here end");
    vector.push_back("last world");
    vector.pop_back();

    number = vector.size();
    LOGE("number = %d", number);
    strTest = vector[number-1];

    int index = strTest.find("end", 0);
    LOGE("string find index = %d", index);
    strTest.replace(index, strTest.size(), "nowhehe");

    return env->NewStringUTF(strTest.c_str());
}


#ifdef __cplusplus
}
#endif

