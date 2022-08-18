#include <jni.h>
#include <string.h>
#include <stdlib.h>

/*
 * Copied ABI definition here: https://github.com/android/ndk-samples/blob/main/hello-jni/app/src/main/cpp/hello-jni.c
 */
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
   #define ABI "mips64"
#elif defined(__mips__)
   #define ABI "mips"
#elif defined(__aarch64__)
   #define ABI "arm64-v8a"
#else
   #define ABI "unknown"
#endif

JNIEXPORT jstring JNICALL
Java_com_ferdinandsilva_ctest_MainActivity_testFunction(JNIEnv* env, jobject thiz)
{
    char *concatenated;
    char text[] = "Hello from JNI! Compiled with ABI ";
    jstring retString;
    concatenated = malloc(strlen(text) + strlen(ABI) + 2);
    strcpy(concatenated, text);
    strcat(concatenated, ABI);
    strcat(concatenated, ".");

    retString = (*env)->NewStringUTF(env, concatenated);
    free(concatenated);

    return retString;
}