//
// Created by adrian on 04.03.17.
//

#include "Palindrome.h"
#include <string>
bool is_palindrome(std::string str)
{
    int wynik = 0;
    size_t dlugosc=str.length();
    for(int i=0;i<dlugosc;i++) {
        if (str[i] != str[dlugosc - i - 1])
            return false;
    }
    return true;
}