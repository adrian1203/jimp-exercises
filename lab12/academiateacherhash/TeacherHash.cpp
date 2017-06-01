//
// Created by Adrian on 2017-05-31.
//

#include "TeacherHash.h"

namespace academia {
    TeacherId::operator int() const {
        return teacher_id_;
    }

    bool TeacherId::operator==(TeacherId teacherid) const {
        return teacherid.teacher_id_ == this->teacher_id_;
    }

    bool TeacherId::operator!=(TeacherId teacherid) const {
        return teacherid.teacher_id_ != this->teacher_id_;
    }

    TeacherId Teacher::Id() const {
        return id_;
    }

    int Teacher::IntId() const {
        return id_;
    }

    string Teacher::Name() const {
        return name_;
    }

    string Teacher::Department() const {
        return department_;
    }

    bool Teacher::operator==(Teacher teacher) const {
        return ((teacher.id_ == this->id_) and (teacher.name_ == this->name_) and
                (teacher.department_ == this->department_));
    }

    bool Teacher::operator!=(Teacher teacher) const {
        return ((teacher.id_ != this->id_) or (teacher.name_ != this->name_) or
                (teacher.department_ != this->department_));
    }

    std::size_t TeacherHash::operator()(const Teacher &teacher) const {
        return (((Hash{}(teacher.IntId()) - Hash{}(teacher.Department())) * (Hash{}(teacher.Name()))) % 997);
    }


}