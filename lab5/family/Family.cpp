//
// Created by adrian on 28.03.17.
//

#include "Family.h"
#include <iostream>
#include <string>
Parent::Parent(string name, string surname, int age, string child){
    name_=name;
    surname_=surname;
    age_=age;
    child_=child;
}
Child::Child(string name, string surname, int age, string school) {
    name_=name;
    surname_=surname_;
    age_=age;
    school_=school;
}
void Child::ChangeSchool(string school) {
    school_=school;
}
/*void Parent::ChangeSchool(Child child, string school){
    child.school_=school;


}*/
