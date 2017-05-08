//
// Created by adrian on 05.04.17.
//
#include <iostream>
#include "StudentRepository.h"
using namespace std;
int main(){
    academia::StudyYear student;
    academia::StudyYear student1;
    cin>>student;
    cin>>student1;
    if(student<student1){
        cout<<"spełnia";
    }
    else{
        cout<<"niespełania";
    }
}
