//
// Created by Adrian on 2017-05-13.
//
#include "Scheduler.h"

namespace academia{

    const Schedule &Schedule::OfTeacher(int teacherid) {
        Schedule teacher;
        for (int i = 0; i < schedule_.size(); ++i) {
            if (schedule_[i].TeacherId() == teacherid) {
                teacher.InsertScheduleItem(schedule_[i]);
            }
        }
        return *this;
    }

    const Schedule Schedule::OfRoom(int room) {
        return Schedule();
    }

    const Schedule Schedule::OfYear(int room) {

        return Schedule();
    }

    std::vector<int> Schedule::AvailableTimeSlots(int room) {
        std::vector<int> i;

        return i;
    }


}

