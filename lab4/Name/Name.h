//
// Created by adrian on 23.03.17.
//

#ifndef JIMP_EXERCISES_NAME_H
#define JIMP_EXERCISES_NAME_H

#include <iostream>
#include <string>
using namespace std;
class Name{
public:
    Name();
    Name(string ToFirstNamesInitials (std::string firstname, string secondname, string thirdname, string surname) ;
    ~Name();

    string ToFullInitials (std::string firstname, string secondname, string thirdname, string surname);
    string ToFirstNamesInitials (std::string firstname, string secondname, string thirdname, string surname);
    string ToSurnameNames ();
    string ToNamesSurname ();

private:
    string firstname_, secondname_,thirdname_, surname_;
};

#endif //JIMP_EXERCISES_NAME_H
