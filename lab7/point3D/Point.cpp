//
// Created by Adrian on 2017-04-19.
//

#include "Point.h"
#include <iostream>
#include <cmath>

namespace geometry {

    Point::Point() : x_(0), y_(0) { std::cout << "konstruktor 2d" << endl; }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
        std::cout << "konstrukr 2d" << endl;
    }

    Point::~Point() { cout << "dekonstruktor 2d" << endl; }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_ = x;
    }

    void Point::SetY(double y) {
        y_ = y;
    }

    std::ostream &operator<<(std::ostream &out, const Point &other) {
        out << "(" << other.GetX() << ", " << other.GetY() << ")";
    }
}