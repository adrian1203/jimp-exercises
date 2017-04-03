//
// Created by adrian on 29.03.17.
//

#include <iostream>
#include "TextPool.h"

namespace pool {
    TextPool::TextPool() {}

    TextPool::~TextPool() {

        str_.clear();
    }

    TextPool::TextPool(initializer_list<string> initializer_str) {

        for (const string &n :initializer_str) {
            if (str_.find(n) == str_.end()) {
                str_.insert(n);
            }
        }
    }

    TextPool::TextPool(TextPool &&other) {

        swap(str_, other.str_);
    }


    TextPool &TextPool::operator=(TextPool &&other) {

        if (this != &other) {
            swap(str_, other.str_);
            return *this;
        }
        return *this;
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        auto ptr_string = str_.insert(str);
        experimental::string_view word = *ptr_string.first;
        return word;

    }

    size_t TextPool::StoredStringCount() const {

        return str_.size();
    }
};
