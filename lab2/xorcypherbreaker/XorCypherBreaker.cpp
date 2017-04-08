//
// Created by adrian on 14.03.17.
//

#include "XorCypherBreaker.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary) {
    string key = "aaa";
    int tmp = 0;
    int word;
    string words;
    string encrypt;
    for (int i = 97; i <= 122; i++) {
        for (int j = 97; j <= 122; j++) {
            {
                for (int k = 97; k < 122; k++) {
                    key[0] = i;
                    key[1] = j;
                    key[2] = k;
                    for (int i = 0; i < cryptogram.size(); i++) {
                        word = (int(cryptogram[i]) xor key[i % 3]);
                        encrypt += char(word);
                    }
                    for (int i = 0; i < dictionary.size(); i++) {
                        words = " " + dictionary[i] + " ";
                        if (encrypt.size() >= encrypt.find(words)) {
                            tmp++;
                        }
                        words.clear();
                    }
                    key[0] = char(i);
                    key[1] = char(j);
                    key[2] = char(k);
                    if (tmp > 5) {
                        return key;
                    }
                    encrypt.clear();
                    tmp = 0;
                }
            }
        }
    }
    return key;
}
