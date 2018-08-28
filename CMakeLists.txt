cmake_minimum_required(VERSION 3.10)
project("eos-sig")
find_package(JNI)
include_directories(${JNI_INCLUDE_DIRS})

file (GLOB sources  Crypto/* ec/* utility/utils.h utility/utils.cpp  signature.h signature.cpp)

add_executable(eos ${sources} main.cpp)
add_library(signaturejni SHARED ${sources} com_SignatureJNI.h com_SignatureJNI.cpp)