//
// Created by Adrian on 2017-05-30.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <iostream>
#include <chrono>

using namespace std;
namespace profiling
{
    template<class T>

    auto TimeRecorder(T foo)
    {
        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        decltype(foo()) var = foo();
        end = chrono::system_clock::now();

        chrono::duration<double, ratio<1, 1000>> time = (end - start);

        return pair<decltype(foo()), double> {var, int(time.count())+1};

    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
