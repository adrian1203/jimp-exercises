//
// Created by adrian on 05.04.17.
//

#include "StudentRepository.h"

namespace academia {


    StudyYear::StudyYear(int studyyear) {
        this->studyyear_ = studyyear;
    }
    StudyYear::StudyYear() {
        this->studyyear_ = 1;
    }
    StudyYear::StudyYear(const StudyYear &other_year) {
        this->studyyear_ = other_year.GetStudyYear();
    }

    StudyYear &StudyYear::operator=(const StudyYear &other_year) {
        this->studyyear_ = other_year.GetStudyYear();
        return *this;
    }
    int StudyYear::GetStudyYear() const {
        return studyyear_;
    }

    void StudyYear::SetStudyYear(int studyyear) {
        studyyear_ = studyyear;
    }

    StudyYear &StudyYear::operator++() {
        this->studyyear_++;
        return *this;
    }

    StudyYear &StudyYear::operator--() {
        this->studyyear_--;
        return *this;

    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }
    istream& operator>>(istream & input, StudyYear& year){
        year.SetStudyYear(ReadNumber(&input));
    }
    ostream& operator<<(std::ostream &out, StudyYear& student){
        strstream ss;;
        out<<student.GetStudyYear();
        return out;
    }
   bool StudyYear:: operator ==( const StudyYear &otheryear) const{
        if(this->studyyear_==otheryear.studyyear_){
            return true;
        }
       return false;
    }
    bool StudyYear:: operator <( const StudyYear &otheryear) const{
        if(this->studyyear_<otheryear.studyyear_){
            return true;
        }
        return false;
    }
     StudyYear::operator int() const{
        return this->studyyear_;
    }

    //-************************************************************************Studnet
    Student::Student(string id, string first_name, string last_name, string program, StudyYear year) {
        id_ = id;
        first_name_ = first_name;
        last_name_ = last_name;
        program_ = program;
        year_ = year;
    }
    Student::Student (){
        id_ = "";
        first_name_ ="";
        last_name_ ="";
        program_ ="";
        year_ = StudyYear();
    }
    Student::Student(const Student &other_student) {
        this->id_ = other_student.id_;
        this->first_name_ = other_student.first_name_;
        this->last_name_ = other_student.last_name_;
        this->program_ = other_student.program_;
        this->year_ = other_student.year_;
    }

    Student &Student::operator=(const Student &other_student) {
        this->id_ = other_student.id_;
        this->first_name_ = other_student.first_name_;
        this->last_name_ = other_student.last_name_;
        this->program_ = other_student.program_;
        this->year_ = other_student.year_;
        return *this;
    }
    std::istream& operator>>(std::istream &is, Student& student){

    }


}
