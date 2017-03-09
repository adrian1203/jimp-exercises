//
// Created by adrian on 09.03.17.
//
#include <string>
#include "ReverseString.h"
std::string reverse(std::string str)
{
    int i=0,j=0;
    std::string revers;
    for(int i=0;i<str.length();i++)
    {
        revers+=str[str.length()-i-1];
        j++;
    }
    return revers;

}