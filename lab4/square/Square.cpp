//
// Created by adrian on 21.03.17.
//

#include "Square.h"
#include <iostream>
#include <cmath>
#include <ostream>

namespace geometry {
    using ::std::ostream;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;

    Square::Square() {}

    Square::~Square() {}

    Square::Square(Point a, Point b, Point c, Point d) {
        if (a.Distance(b) != b.Distance(d) and a.Distance(c)!=sqrt(2)*a.Distance(b)) {
            a_.SetX(0);
            a_.SetY(0);
            b_.SetX(0);
            b_.SetY(0);
            c_.SetX(0);
            c_.SetY(0);
            d_.SetX(0);
            d_.SetY(0);
        } else {
            a_ = a;
            b_ = b;
            c_ = c;
            d_ = d;
        }
    }

    double Square::Circumference() const {

        return a_.Distance(b_) * 4;
    }

    double Square::Area() const {

        return a_.Distance(b_) * a_.Distance(b_);
    }


}
