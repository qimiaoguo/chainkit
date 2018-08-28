#include "com_SignatureJNI.h"
#include <iostream>
#include "signature.h"

using namespace std;

JNIEXPORT jstring JNICALL Java_com_SignatureJNI_sign
      (JNIEnv *env, jobject, jstring hash, jstring pri_key) {
   string hash_str = (*env).GetStringUTFChars(hash, NULL);
   string pri_key_str = (*env).GetStringUTFChars(pri_key, NULL);

   auto sig = sign(hash_str, pri_key_str);
   jstring result = (*env).NewStringUTF( string(sig).c_str());
   return result;
}

/*
 * Class:     com_SignatureJNI
 * Method:    verify
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jboolean JNICALL Java_com_SignatureJNI_verify
      (JNIEnv *env, jobject, jstring hash, jstring sig, jstring pub_key) {

   string hash_str = (*env).GetStringUTFChars(hash, NULL);
   string sig_str = (*env).GetStringUTFChars(sig, NULL);
   string pub_key_str = (*env).GetStringUTFChars(pub_key, NULL);

   return (jboolean)verify(hash_str, sig_str, pub_key_str);
}

