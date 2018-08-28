//
// Created by 郭其淼 on 2018/8/28.
//

#ifndef EOS_SIG_SIGNATURE_H
#define EOS_SIG_SIGNATURE_H

#include <iostream>
#include <vector>

std::string sign(const std::vector<unsigned char> &packed_bytes, const std::vector<unsigned char> &pri_key);

std::string sign(const std::string &hash, const std::string &pri_key_wif);

bool verify(const std::vector<unsigned char> &packed_bytes, const std::string &signature, const std::vector<unsigned char> &pub_key);

bool verify(const std::string &hash, const std::string &signature, const std::string &pub_key_wif);

#endif //EOS_SIG_SIGNATURE_H
