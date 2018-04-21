#include <jni.h>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>

#include <android/log.h>
#define LOG_TAG    "TestAndroidJNI"

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)


JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestVector(JNIEnv *env, jobject /* this */){
    string strTest;
    int number;

    LOGI(">>>>>>>>>nativeTestVector start>>>>>>>>>>>>");

    vector<string> vector;
    vector.push_back("test1");
    vector.push_back("test2");
    vector.push_back("test3");
    vector.push_back("test4 i am here end");
    vector.push_back("last world");

    // vector 遍历
    std::vector<std::string>::iterator it;
    for (it = vector.begin(); it < vector.end(); it++) {
        LOGD("vector[%s]", it->c_str());
    }

    vector.pop_back();
    number = vector.size();
    LOGE("number = %d", number);
    strTest = vector[number-1];

    int index = strTest.find("end", 0);
    LOGE("string find index = %d", index);
    strTest.replace(index, strTest.size(), "nowhehe");


    LOGI(">>>>>>>>>nativeTestVector end>>>>>>>>>>>>");
    return env->NewStringUTF(strTest.c_str());
}


JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestList(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestList start>>>>>>>>>>>>");

    string strTest;
    list<string> list1;
    list1.push_back("hello");
    list1.push_front("world");

    strTest = list1.front();
    LOGE("str: %s", strTest.c_str());

    strTest = list1.back();
    LOGE("str: %s", strTest.c_str());

    list1.pop_back();
    LOGE("str: %s", strTest.c_str());
    strTest = list1.front();
    LOGE("str: %s", strTest.c_str());

    LOGI(">>>>>>>>>nativeTestList end>>>>>>>>>>>>");
    return env->NewStringUTF(strTest.c_str());
}

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestQueue(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestQueue start>>>>>>>>>>>>");

    string str = "hello";
    queue<char> q;
    // 添加元素
    q.push('A');
    q.push('B');
    q.push('C');

    // 添加头部,原来有就覆盖
    q.front() = 'O';

    // 添加尾部,原来有就覆盖
    q.back() = 'D';

    // 遍历并出队删除元素
    int size = q.size();
    for (int i = 0; i < size && !q.empty(); i++) {
        LOGD("queue[%d]=[%c]", i, q.front());
        q.pop();
    }

    LOGD("after pop queue.size()=%d", q.size());


    LOGI(">>>>>>>>>nativeTestQueue end>>>>>>>>>>>>");
    return env->NewStringUTF(str.c_str());
}


#ifdef __cplusplus
}
#endif

