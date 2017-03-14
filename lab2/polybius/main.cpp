//
// Created by adrian on 09.03.17.
//

#include "Polybius.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(int argc, char **argv)
{
    std::ifstream myfile(argv[1]);
    std::string word;

    if(!myfile)
        std::cout << "Nie można otworzyć pliku!";

    while(myfile >> word)

    myfile.close();
    std::string zakodowany;
    if(argv[3]==1){
         zakodowany=PolybiusCrypt(word);
    }
    else{
        zakodowany=PolybiusDecrypt(word);
    }
    std::ofstream myfile1 (argv[2], ios_base::in | ios_base::app);
    if(!myfile1)
    std::cout << "Nie można otworzyć pliku!";

    myfile1 << zakodowany;

    myfile1.close();

}