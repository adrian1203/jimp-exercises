//
// Created by Adrian on 2017-04-19.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include <iostream>
#include "Point.h"

using namespace std;
namespace geometry {

    class Point3d : public Point {
    public:
        Point3d() : Point(), z_(0) { std::cout << "konstruktor 3d" << endl; }

        Point3d(double x = 0, double y = 0, double z = 0) : Point(x, y), z_(z) {
            std::cout << "konstruktor 3d" << endl;
        }

        ~Point3d() { std::cout << "dekonstruktor 3d" << endl; }

        double GetZ() const;

        void SetZ(double z);

        double Distance(const Point3d &other) const;

    private:
        double z_;
    };
}


#endif //JIMP_EXERCISES_POINT3D_H
