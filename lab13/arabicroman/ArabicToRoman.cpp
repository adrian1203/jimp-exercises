//
// Created by Adrian on 2017-06-01.
//

#include "ArabicToRoman.h"
using namespace std;
namespace arabicroman {

    string ConversionToRoman(int value) {
        if (value > 3999 or value < 0) {
            return "";
        }
        string rezults="";
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V","IV", "I"};
        int arabic[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<13;i++){
            while(value>=arabic[i]){
                value-=arabic[i];
                rezults+=roman[i];
            }
        }
        return rezults;
    }
    string ConversionToArabic(string number){
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V","IV", "I"};
        int arabic[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        return "";
    }
}