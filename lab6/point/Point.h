//
// Created by adrian on 05.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>
using namespace std;
class Point {
public:

    Point();

    Point(double x, double y);

    ~Point();

    double GetX() const;
    double GetY() const;
    void SetX(double x);
    void SetY(double y);

private:
    double x_, y_;
};

std::istream& operator>>(std::istream &is, Point& point);
std::ostream& operator<<(std::ostream &out, Point& point);

#endif //JIMP_EXERCISES_POINT_H
