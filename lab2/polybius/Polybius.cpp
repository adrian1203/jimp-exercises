//
// Created by adrian on 09.03.17.
//

#include "Polybius.h"
#include <string>
#include <map>
std::string PolybiusCrypt(std::string message)
{
    std::string zakodowany;
    std::map< char, std::string> szyfr;
    szyfr['a']="11";szyfr['b']="12";szyfr['c']="13";szyfr['d']="14";szyfr['e']="15";
    szyfr['f']="21";szyfr['g']="22";szyfr['h']="23";szyfr['j']="24";szyfr['i']="24";szyfr['k']="25";
    szyfr['l']="31";szyfr['m']="32";szyfr['n']="33";szyfr['o']="34";szyfr['p']="35";
    szyfr['q']="41";szyfr['r']="42";szyfr['s']="43";szyfr['t']="44";szyfr['u']="45";
    szyfr['v']="51";szyfr['w']="52";szyfr['x']="53";szyfr['y']="54";szyfr['z']="55";
    int dlugosc = message.length();
    for (int i = 0; i < dlugosc; i++) {
        if (int(message[i]) >= 65 and int(message[i]) <= 90) {
            message[i] = int(message[i]) + 32;
        }
        if (int(message[i]) >= 97 and int(message[i]) <= 122) {
            zakodowany += (szyfr[message[i]]);
        }
    }
    return zakodowany;
}
std::string PolybiusDecrypt(std::string crypted)
{
    std::string odszyfrowany;
    std::map< int, std::string> slownik;
    slownik[11]="a";slownik[12]="b";slownik[13]="c";slownik[14]="d";slownik[15]="e";
    slownik[21]="f";slownik[22]="g";slownik[23]="h";slownik[24]="j";slownik[24]="i";slownik[25]="k";
    slownik[31]="l";slownik[32]="m";slownik[33]="n";slownik[34]="o";slownik[35]="p";
    slownik[41]="q";slownik[42]="r";slownik[43]="s";slownik[44]="t";slownik[45]="u";
    slownik[51]="v";slownik[52]="w";slownik[53]="x";slownik[54]="y";slownik[55]="z";
    int dlugosc = crypted.length();
    for (int i = 0; i < dlugosc; i = i + 2) {
        std::string tmp;
        tmp[0] = crypted[i];
        tmp[1] = crypted[i + 1];
        int liczba = std::stoi(tmp);
        odszyfrowany += slownik[liczba];
    }
    return odszyfrowany;
}