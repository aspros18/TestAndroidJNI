#include <jni.h>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>

#include <android/log.h>
#include <string.h>
#include "algorithm.h"
#include "structures.h"
#include <iostream>


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

char buffer[100] = {0};
string dump(int* arr, int size)
{
    string str;
    char temp[5] = {0};
    memset(buffer, 0, sizeof(buffer));

    for (int i = 0; i < size; i ++) {
        sprintf(temp, "%d ", arr[i]);
        strcat(buffer, temp);
    }

    str = buffer;
    return str;
}

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestVector(JNIEnv *env, jobject /* this */){
    string strTest;
    int number;
    int arr[10] = {5, 2, -4, 3, 6, 7, 8, 10, 4, 11};
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


    // buble sort test
    int len = sizeof(arr)/sizeof(int);
    LOGE("before buble sort arr is: %s", dump(arr, 10).c_str());
    merge_sort(arr, 0, len - 1);
    LOGE("after  buble sort arr is: %s", dump(arr, 10).c_str());

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

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestStack(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestStack start>>>>>>>>>>>>");

    string ret = "hello";
    stack<char> st;
    st.push('A');
    st.push('B');
    st.push('C');

    string str;
    while (!st.empty()) {
        str.push_back(st.top());
        str.push_back(' ');
        st.pop(); // 从栈顶出

        if (st.empty())
            LOGD("stack[%s]", str.c_str());
    }

    LOGD("after pop stack.size()=%d", st.size());

    LOGI(">>>>>>>>>nativeTestStack end>>>>>>>>>>>>");
    return env->NewStringUTF(ret.c_str());
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

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestDeque(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestDeque start>>>>>>>>>>>>");

    string str = "hello";
    deque<char> deque1;
    // 添加元素
    deque1.push_back('A');
    deque1.push_back('B');
    deque1.push_back('C');
    deque1.push_front('O');
    deque1.push_back('D');

    deque<char> deque2(deque1);

    // deque 遍历,队前出
    std::deque<char>::iterator it;
    string str1;
    for (it = deque1.begin(); it < deque1.end(); it++) {
        str1.push_back(deque1.front());
        str1.push_back(' ');
        deque1.pop_front(); // 队前出

        if (deque1.empty())
            LOGD("deque1[%s]", str1.c_str());
    }

    LOGD("after pop deque1.size()=%d", deque1.size());

    // deque 遍历, 队后出
    string str2;
    while (!deque2.empty()) {
        str2.push_back(deque2.back());
        str2.push_back(' ');
        deque2.pop_back(); // 队后出

        if (deque2.empty())
            LOGD("deque2[%s]", str2.c_str());
    }

    LOGD("after pop deque2.size()=%d", deque2.size());



    LOGI(">>>>>>>>>nativeTestDeque end>>>>>>>>>>>>");
    return env->NewStringUTF(str.c_str());
}


JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestMap(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestMap start>>>>>>>>>>>>");
    string ret = "hello";

    // map 内部用红黑二叉树实现
    map<int, string> map1;
    map1.insert(pair<int, string>(1, "LiMei"));
    map1.insert(map<int, string>::value_type(2, "luxi"));
    map1[3] = "jack ma";

    map<int, string>::iterator it;

    string str;
    for(it = map1.begin(); it != map1.end(); it++){
        str += "[";
        str += it->second;
        str += "] ";
    }

    LOGD("map1:%s", str.c_str());

    // 查找
    int key = 2;
    it = map1.find(key);
    if (it == map1.end())
        LOGD("key is %d, not found value", key);
    else
        LOGD("key is %d, found value=%s", key, it->second.c_str());

    LOGI(">>>>>>>>>nativeTestMap end>>>>>>>>>>>>");
    return env->NewStringUTF(ret.c_str());
}

JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestSet(JNIEnv *env, jobject /* this */){
    LOGI(">>>>>>>>>nativeTestSet start>>>>>>>>>>>>");
    string ret = "hello";

    // set 内部平衡二叉树实现
    string strArr[5] = {"LiMei", "luxi", "jack ma", "robin", "pony ma"};
    set<string> set1(strArr, strArr+5);
    set1.insert("somebody");
    set1.insert("pony ma"); // 用重复值插入, 不会对大小产生影响
    set1.insert("luxi");    // 用重复值插入

    // 遍历set
    set<string>::iterator it;
    string str;
    for(it = set1.begin(); it != set1.end(); it++){
        str += "[";
        str += *it;
        str += "] ";
    }

    LOGD("set1:%s", str.c_str());

    // 查找
    it = set1.find("pony ma");
    if (it != set1.end())
        LOGD("found %s in set", it->c_str());
    else
        LOGD("not found in set");

    LOGI(">>>>>>>>>nativeTestSet end>>>>>>>>>>>>");
    return env->NewStringUTF(ret.c_str());
}


JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_nativeTestStructures(JNIEnv *env, jobject /* this */)
{
    LOGI(">>>>>>>>>nativeTestStructures start>>>>>>>>>>>>");
    string ret = "hello";

    Complex tatol(0,0), tatol2(0,0);
    Complex complex1(3.0, 5.1);
    Complex complex2(6.1, 8.2);

    tatol = complex1 + complex2;
    tatol2 = operator+(complex1, complex2);

    LOGD("tatol dReal=%.02f dImag=%.02f", tatol.dReal, tatol.dImag);
    LOGD("tatol2 dReal=%.02f dImag=%.02f", tatol2.dReal, tatol2.dImag);
    LOGI(">>>>>>>>>nativeTestStructures end>>>>>>>>>>>>");
    return env->NewStringUTF(ret.c_str());
}


#ifdef __cplusplus
}
#endif

