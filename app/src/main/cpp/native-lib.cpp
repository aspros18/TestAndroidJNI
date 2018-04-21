#include <jni.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>

extern "C"
{

    JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jstring JNICALL Java_com_aspros_testandroidjni_MainActivity_testVector(JNIEnv *env, jobject /* this */){
        std::string strTest;
        int number;

        std::vector<std::string> vector;
        vector.push_back("last world");

        number = vector.capacity();
        strTest = vector[number-1];

        return env->NewStringUTF(strTest.c_str());
    }
}


