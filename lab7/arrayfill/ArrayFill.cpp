//
// Created by Adrian on 2017-04-20.
//

#include <random>
#include <vector>
#include <memory>
#include "ArrayFill.h"

namespace arrays {
    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return start_ + step_ * index;
    }

    int RandomFill::Value(int index) const {
        return (*dis_)(*gen_);
    }

    int SquaredFill::Value(int index) const {
        return a_ * index * index + b_;
    }

    void FillArray(size_t size, const ArrayFill &fill, vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(fill.Value(i));
        }

    }
}
