//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int Factorial(int value) {
    if(value>12 or value<-12)
    {
        return 0;
    }
    if(value==0)
    {
        return 1;
    }
    if(value>0)
    {
        return value*Factorial(value-1);
    }
    return value*Factorial(value+1);


}
