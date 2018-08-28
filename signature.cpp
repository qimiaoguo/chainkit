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
std::string sign(const std::vector<unsigned char> &packedBytes, const std::vector<unsigned char> &pri_key)
{
   uint8_t signature[uECC_BYTES * 2] = { 0 };
   int recId = uECC_sign_forbc(pri_key.data(), packedBytes.data(), signature);
   if (recId == -1) {
      // could not find recid, data probably already signed by the key before?
      return "";
   } else {
      //std::cout<<(checkSignature(pub_key.data(), packedSha256, signature)!=-1)<<std::endl;
      unsigned char bin[65+4] = { 0 };
      unsigned char *rmdhash = NULL;
      int binlen = 65+4;
      int headerBytes = recId + 27 + 4;
      bin[0] = (unsigned char)headerBytes;
      memcpy(bin + 1, signature, uECC_BYTES * 2);

      unsigned char temp[67] = { 0 };
      memcpy(temp, bin, 65);
      memcpy(temp + 65, "K1", 2);

      rmdhash = RMD(temp, 67);
      memcpy(bin + 1 +  uECC_BYTES * 2, rmdhash, 4);

      char sigbin[100] = { 0 };
      size_t sigbinlen = 100;
      b58enc(sigbin, &sigbinlen, bin, binlen);
      std::string sig = "SIG_K1_";
      sig += sigbin;
      return sig;
   }
}

std::string sign(const std::string &hash, const std::string &pri_key_wif) {
   std::vector<unsigned char> packed_bytes(hash.begin(), hash.end());
   return sign(Utils::convertHexStrToBytes(packed_bytes), eos_key::get_private_key_by_wif(pri_key_wif));
}

bool verify(const std::vector<unsigned char> &packed_bytes, const std::string& signature, const std::vector<unsigned char> &pub_key) {
   uint8_t bin[69] = {0};
   size_t len = 69;
   b58tobin(&bin, &len, signature.substr(7).data(), signature.length() - 7);
   return checkSignature(pub_key.data(), packed_bytes.data(), &bin[1]) != -1;
}

bool verify(const std::string &hash, const std::string& signature, const std::string &pub_key_wif) {
   std::vector<unsigned char> packed_bytes(hash.begin(), hash.end());
   return verify(Utils::convertHexStrToBytes(packed_bytes), signature, eos_key::get_public_key_by_eos_pub(pub_key_wif));
}