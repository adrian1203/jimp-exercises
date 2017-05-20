//
// Created by Adrian on 2017-05-18.
//
#include <iostream>
#include <string>
#include <Sum.h>
#include <complex>

using namespace std;
int main(){
    double a=9.90;
    int b=9;
    complex<int> v(10,3);
    complex<double> v1(5.90,25);
    cout<<Sum<complex<int>>(v,v1);
    return 0;
}

