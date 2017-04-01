//
// Created by adrian on 30.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <iostream>
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
namespace pool{
    class TextPool {
    public:
        TextPool(){}
        //~TextPool(){ set_.clear();}
        TextPool(const std::initializer_list<std::string> &elements);
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;
        //pierwszy
        //TextPool(const TextPool &other);

    private:
        std::experimental::string_view counter_;
        std::set<std::string> set_;
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
