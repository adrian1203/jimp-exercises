//
// Created by Adrian on 2017-05-18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
#include <string>
using namespace std;
namespace factoryMethod {
    template<class T>
    T Create(){
        return T();
    }

    class MyType {
    public:
        MyType(){};
        string SayHello() const { return "hello"; }
    private:
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
