#include <jni.h>
#include <string>
#include <algorithm>  // 引入用于字符串翻转的算法头文件

// 实现字符串翻转的 JNI 函数
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mydemo_MainActivity_flipString(
        JNIEnv* env,
        jobject /* this */,
        jstring inputStr) {
    // 将jstring类型转换为C++的std::string类型
    const char* inputChars = env->GetStringUTFChars(inputStr, nullptr);
    std::string strToFlip(inputChars);
    env->ReleaseStringUTFChars(inputStr, inputChars);  // 释放获取的字符串资源

    // 使用std::reverse算法对字符串进行翻转
    std::reverse(strToFlip.begin(), strToFlip.end());

    // 将翻转后的C++字符串再转换回jstring类型返回
    return env->NewStringUTF(strToFlip.c_str());
}