//
// Created by Adrian on 2017-04-19.
//

#include "Point3D.h"
#include <iostream>
#include <cmath>

namespace geometry {


    double Point3d::GetZ() const {
        return z_;
    }

    void Point3d::SetZ(double z = 0) {
        z_ = z;
    }

    double Point3d::Distance(const Point3d &other) const {
        return sqrt(
                pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2) + pow(other.GetZ() - this->GetZ(), 2));
    }
}
