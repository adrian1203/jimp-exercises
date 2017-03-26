//
// Created by adrian on 21.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H
#include "Point.h"

#include <iostream>
#include <iostream>
#include <cmath>
#include <ostream>
namespace geometry{

    class Square;

    class Square{
    private:
        Point a_,b_,c_,d_;
    public:
        Square();
        Square(Point a,Point b,Point c,Point d );
        ~Square();
        double Circumference() const;
        double Area() const;
    };

}

#endif //JIMP_EXERCISES_SQUARE_H
