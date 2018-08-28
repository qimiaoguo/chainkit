#include <jni.h>
/* Header for class com_SignatureJNI */

#ifndef _Included_com_SignatureJNI
#define _Included_com_SignatureJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_SignatureJNI
 * Method:    sign
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_SignatureJNI_sign
      (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_SignatureJNI
 * Method:    verify
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jboolean JNICALL Java_com_SignatureJNI_verify
      (JNIEnv *, jobject, jstring, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif