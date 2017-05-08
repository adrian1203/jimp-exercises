//
// Created by adrian on 05.04.17.
//

#include "Point.h"
#include <iomanip>
#include <iostream>
#include <strstream>
#include <istream>


using ::std::istream;
using ::std::ws;
Point::Point() : x_(0), y_(0) {}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
}

Point::~Point() {}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}
double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}


istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}
std::ostream& operator<<(std::ostream &out, Point& point){
    out<<"("<<point.GetX()<<","<<point.GetY()<<")";
    return out;
}