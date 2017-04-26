//
// Created by adrian on 23.03.17.
//

#include "Name.h"
#include <iostream>
#include <string>
using namespace std;
Name::Name() : firstname_(""), secondname_(""), thirdname_(""), surname_(""){};
/*Name::Name(string firstname, string secondname, string thirdname, string surname) {
    firstname_=firstname;
    secondname_=secondname;
    thirdname_=thirdname;
    surname_=surname;
}*/
Name::Name(string firstname, string secondname, string thirdname, string surname) {
    firstname_=firstname;
    secondname_=secondname;
    thirdname_=thirdname;
    surname_=surname;
}
string ToFullInitials (std::string firstname, string secondname, string thirdname, string surname){
    string tmpstr="";
    tmpstr=firstname[0]+". ";
    if(secondname[0]!='')tmpstr+=secondname[0]+". ";
    if(thirdname[0]!='')tmpstr+=thirdname[0]+". ";
    tmpstr+=surname[0]+". ";
    return tmpstr;
}
string ToFirstNamesInitials (std::string firstname, string secondname, string thirdname, string surname){
    string tmpstr="";
    tmpstr=firstname[0]+". ";
    if(secondname[0]!='')tmpstr+=secondname[0]+". ";
    if(thirdname[0]!='')tmpstr+=thirdname[0]+". ";
    tmpstr+=surname[0]+". ";
    return tmpstr;
}
