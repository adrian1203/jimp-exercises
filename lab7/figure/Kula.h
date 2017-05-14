//
// Created by Adrian on 2017-04-20.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "iostream"
#include "Kolo.h"

class Kula : public Kolo {
public:
    Kula(double x, double y, double z, double r) : Kolo(x, y, r), z_(z) {}

    virtual double Pole() const override;

private:
    double z_;
};


#endif //JIMP_EXERCISES_KULA_H
