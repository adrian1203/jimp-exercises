//
// Created by Adrian on 2017-04-19.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>

using namespace std;
namespace geometry {
    class Point {
    public:
        Point();

        Point(double x, double y);

        ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

        void SetX(double x);

        void SetY(double y);

        friend std::ostream &operator<<(std::ostream &out, const Point &other);

    private:
        double x_, y_;
    };

    std::ostream &operator<<(std::ostream &out, const Point &other);
}

#endif //JIMP_EXERCISES_POINT_H
