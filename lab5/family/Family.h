//
// Created by adrian on 28.03.17.
//

#ifndef JIMP_EXERCISES_FAMILY_H
#define JIMP_EXERCISES_FAMILY_H

#include <iostream>
#include <string>
using namespace std;
class Parent{
public:
    Parent(){}
    ~Parent(){}
    Parent(string name, string surname, int age, string child);
    //friend class Child;
    //void ChangeSchool( string school){
    //}

private:
    string name_;
    string surname_;
    int age_;
    string child_;
};
class Child{
public:
    Child(){}
    ~Child(){}
    Child(string name, string surname, int age, string school);
    friend class Parent;
    void ChangeSchool(string school);

private:
    string name_;
    string surname_;
    int age_;
    string school_;
};
#endif //JIMP_EXERCISES_FAMILY_H
