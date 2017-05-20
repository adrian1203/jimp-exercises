//
// Created by Adrian on 2017-05-18.
//

#ifndef JIMP_EXERCISES_VALUE_H
#define JIMP_EXERCISES_VALUE_H

#include <iostream>
#include <vector>

template<class T>
T Mean(std::vector<T> v){
    T sum = T();
    for(T u:v){
        sum+= u;
    }
    T mean = v.size();
    return sum / mean;
}
#endif //JIMP_EXERCISES_VALUE_H
