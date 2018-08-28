//
// Created by 郭其淼 on 2018/8/28.
//

#include "./ec/eos_key_encode.h"
#include "./Crypto/libbase58.h"
#include "./utility/utils.h"
#include "./ec/sha256.h"
#include "signature.h"

extern "C"
{
#include "./Crypto/sha2.h"
#include "./Crypto/uECC.h"
#include "./Crypto/rmd160.h"
}

#include <iostream>
#include <chrono>


//std::string sign(const std::vector<unsigned char> &pri_key, const std::vector<unsigned char> &pub_key, std::vector<unsigned char> packedBytes)
//{
//
//   uint8_t packedSha256[SHA256_DIGEST_LENGTH];
//   sha256_Raw(packedBytes.data(), packedBytes.size(), packedSha256);
//
//   uint8_t signature[uECC_BYTES * 2] = { 0 };
//   int recId = uECC_sign_forbc(pri_key.data(), packedSha256, signature);
//   if (recId == -1) {
//      // could not find recid, data probably already signed by the key before?
//      return "";
//   } else {
//      //std::cout<<(checkSignature(pub_key.data(), packedSha256, signature)!=-1)<<std::endl;
//      unsigned char bin[65+4] = { 0 };
//      unsigned char *rmdhash = NULL;
//      int binlen = 65+4;
//      int headerBytes = recId + 27 + 4;
//      bin[0] = (unsigned char)headerBytes;
//      memcpy(bin + 1, signature, uECC_BYTES * 2);
//
//      unsigned char temp[67] = { 0 };
//      memcpy(temp, bin, 65);
//      memcpy(temp + 65, "K1", 2);
//
//      rmdhash = RMD(temp, 67);
//      memcpy(bin + 1 +  uECC_BYTES * 2, rmdhash, 4);
//
//      char sigbin[100] = { 0 };
//      size_t sigbinlen = 100;
//      b58enc(sigbin, &sigbinlen, bin, binlen);
//      std::string sig = "SIG_K1_";
//      sig += sigbin;
//      return sig;
//   }
//}

//bool verify(const std::string& signature, const std::vector<unsigned char> &pubKey, std::vector<unsigned char> &packedBytes) {
//   uint8_t packedSha256[SHA256_DIGEST_LENGTH];
//   sha256_Raw(packedBytes.data(), packedBytes.size(), packedSha256);
//   uint8_t bin[69] = {0};
//   size_t len = 69;
//   b58tobin(&bin, &len, signature.substr(7).data(), signature.length() - 7);
//   return checkSignature(pubKey.data(), packedSha256, &bin[1]) != -1;
//}
//
//bool signTest(const std::vector<unsigned char> &signatureHex, const std::vector<unsigned char> &pubKey, std::vector<unsigned char> packedBytes)
//{
//   uint8_t packedSha256[SHA256_DIGEST_LENGTH];
//   sha256_Raw(packedBytes.data(), packedBytes.size(), packedSha256);
//
//   std::vector<unsigned char> signature = Utils::convertHexStrToBytes(signatureHex);
//   signature.erase(signature.begin());   //remove headerBytes
//
//   return checkSignature(pubKey.data(), packedSha256, signature.data()) != -1;
//}

int main() {
   std::string wif_pub_key = "EOS7ofXJ6D1H1QYDYKyGR576tJ21t42TxkWrKwZTBUBKwbiF3HUGz";
   std::string wif_pri_key = "5JZ6Zjr3eTcoC5h1kj9sx66U7w6p5kDtts4Mgjh1yCGARng4gb6";
   std::string s = "useraaaaaaad";
   std::vector<unsigned char> data(s.begin(), s.end());

   auto now = std::chrono::system_clock::now();

//   for (int i = 0; i <100; i++) {
//      sign(eos_key::get_private_key_by_wif(wif_pri_key), eos_key::get_public_key_by_eos_pub(wif_pub_key), data);
//   }
   std::cout<<(std::chrono::system_clock::now() - now).count()<<std::endl;
   //std::string signature = sign(eos_key::get_private_key_by_wif(wif_pri_key), eos_key::get_public_key_by_eos_pub(wif_pub_key),data);
   std::string signature = sign("7af85099ef7ed2ceb9a70f50db54f426f227203797bc95844aff6c1112733434", wif_pri_key);
   std::cout<<signature<<std::endl;

   std::cout<<verify("7af85099ef7ed2ceb9a70f50db54f426f227203797bc95844aff6c1112733434",signature, wif_pub_key);
   return 0;
}