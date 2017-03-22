//
// Created by adrian on 16.03.17.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>

using namespace std;
namespace tinyurl {
    struct TinyUrlCodec;
    std::unique_ptr<TinyUrlCodec> Init() {
        TinyUrlCodec url;
        unique_ptr<TinyUrlCodec> ptr(new TinyUrlCodec);
        return ptr;
    }

    void NextHash(std::array<char, 6> *state) {
        for (int i = 5; i > -1; i--) {
            int a = int((*state)[i]);
            if ((a > 47 and a < 57) or (a > 96 and a < 122) or (a > 65 and a < 90)) {
                (*state)[i] = char(a + 1);
                i = -1;
            }
            if (a == 57 or a == 58) {
                (*state)[i] = char(65);
                i = -1;
            }
            if (a == 90 or a == 91) {
                (*state)[i] = char(97);
                i = -1;
            }
            if (a >= 122) {
                (*state)[i] = '0';
                int b = int((*state)[i - 1]);
                (*state)[i - 1] = char(b + 1);
                b = int((*state)[i - 1]);
                if (b != 58 and b != 91 and b != 123) {
                    i = -1;
                }
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
        string result = "aaaaaa";
        for (int i = 0; i < 6; i++) {
            result[i] = (*codec)->state[i];

        }
        (*codec)->codes[result] = url;

        NextHash(&(*codec)->state);
        return result;

    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        if (codec->codes.find(hash) != codec->codes.end())return codec->codes[hash];

    }
}

