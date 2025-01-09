#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mydemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_com_example_mydemo_MainActivity_summaryFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jint num1,
        jint num2) {
    jint sum = num1 + num2;
    return sum;
}