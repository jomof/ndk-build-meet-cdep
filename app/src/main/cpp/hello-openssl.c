/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <stdio.h>
#include <jni.h>
#include <openssl/md5.h>

jstring
Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env, jobject this) {

    const int digestLength = 16;

    // The message to hash
    char input[] = "Facts do not cease to exist because they are ignored.";

    // The binary hash of the message
    unsigned char output[digestLength];

    // Do the actual hashing
    MD5((unsigned char*)&input, strlen(input), (unsigned char*) &output);

    // Convert to a hex string for display
    char digest[digestLength * 2 + 1] = {0} ;
    for(int i = 0; i < digestLength; i++) {
        sprintf(&digest[i*2], "%02x", (unsigned int) output[i]);
    }

    char message[1024];
    sprintf(message, "Hello from CDep OpenSSL package!\nMD5 Digest %s", digest);

    jstring result = (*env)->NewStringUTF(env, message);

    return result;
}
