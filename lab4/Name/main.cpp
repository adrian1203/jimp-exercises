//
// Created by adrian on 23.03.17.
//
#include "Name.h"
#include "Name.cpp"
#include <iostream>
using namespace std;
int main(){
    Name tmp1("Adrian", "Drugie", "Trzecie", "Nazwisko");
    cout<<ToFullInitials("Adrian", "Drugie", "Trzecie", "Nazwisko");
}


