//
// Created by adrian on 05.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include "iostream"
#include "strstream"
#include <string>
#include <iomanip>
#include <iostream>
#include <strstream>
#include <istream>
using namespace std;
namespace academia{
    class StudyYear{
    private:
        int studyyear_;
    public:
        StudyYear();
        StudyYear(int studyyear);
        StudyYear(const StudyYear &otheryear);
        StudyYear &operator=(const StudyYear &otheryear);
        StudyYear &operator++();
        StudyYear &operator--();
        bool operator ==( const StudyYear &otheryear) const;
        bool operator <( const StudyYear &otheryear) const;
        operator int() const;
        int GetStudyYear() const;
        void SetStudyYear(int studyyear);

    };
    class Student{
    private:
        string id_;
        string first_name_;
        string last_name_;
        string program_;
        StudyYear year_;
    public:
        Student ();
        Student(string id,string first_name,string last_name,string program,StudyYear year);
        Student(const Student &other_student);
        Student &operator=(const Student &other_student);



    };

    std::istream& operator>>(std::istream &is, StudyYear& year);
    std::ostream& operator<<(std::ostream &out, StudyYear& year);
    std::istream& operator>>(std::istream &is, Student& student);
    std::ostream& operator<<(std::ostream &out, Student& student);
    double ReadNumber(istream* is);
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
