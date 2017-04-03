//
// Created by adrian on 29.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

using namespace std;
namespace pool {
    class TextPool {
    public:
        TextPool();

        ~TextPool();

        TextPool(initializer_list<string> initstr);

        TextPool(TextPool &&other);

        TextPool &operator=(TextPool &&other);

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        set<string> str_;
    };
};

#endif //JIMP_EXERCISES_TEXTPOOL_H