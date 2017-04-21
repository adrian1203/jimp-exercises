//
// Created by Adrian on 2017-04-20.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H

#include "iostream"

class Kolo {
public:
    Kolo(double x, double y, double r) : x_(x), y_(y), r_(r) {};

    virtual double Pole() const;

protected:
    double x_, y_, r_;
};


#endif //JIMP_EXERCISES_KOLO_H
