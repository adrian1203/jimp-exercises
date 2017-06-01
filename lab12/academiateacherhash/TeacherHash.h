//
// Created by Adrian on 2017-05-31.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>
#include <cmath>

using namespace std;
namespace academia {
    class TeacherId {
    public:
        TeacherId(int teacher_id) : teacher_id_{teacher_id} {};

        bool operator==(TeacherId teacherid) const;

        bool operator!=(TeacherId teacherid) const;

        operator int() const;

    private:
        int teacher_id_;
    };

    class Teacher {
    public:
        Teacher(TeacherId id, string name, string departmen) : id_{id}, name_{name}, department_{departmen} {};

        TeacherId Id() const;

        int IntId() const;

        string Name() const;

        string Department() const;

        bool operator==(Teacher teacher) const;

        bool operator!=(Teacher teacher) const;

    private:
        TeacherId id_;
        std::string name_, department_;
    };

    class TeacherHash {
    public:
        TeacherHash() {};//konstruktor
        size_t operator()(const Teacher &teacher) const;//operator wywołania funkcji
    };

    struct Hash {
    public:
        template<class T>//operator wywołąnie funckcji
        size_t operator()(T x) const {
            return (hash<T>()(x));
        }
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
