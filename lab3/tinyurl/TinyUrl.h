//
// Created by adrian on 16.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <map>
namespace tinyurl{
    struct TinyUrlCodec{
        std::array<char, 6> state;
        std::map<std::string,std::string> codes;
    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);}

#endif //JIMP_EXERCISES_TINYURL_H
