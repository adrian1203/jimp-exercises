//
// Created by Adrian on 2017-05-13.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <list>
#include <array>
#include <memory>
using namespace std;
namespace academia {
    class SchedulingItem;
    class SchedulingItem {
    public:
        SchedulingItem(std::initializer_list<unsigned long> it) {
            std::copy(it.begin(), it.end(), scheduling_.begin());
        }

        int CourseId() const { return scheduling_[0]; }

        int TeacherId() const { return scheduling_[1]; };

        int RoomId() const { return scheduling_[2]; };

        int TimeSlot() const { return scheduling_[3]; }

        int Year() const { return scheduling_[4]; }

    private:
        vector<int> scheduling_;
    };

    class Schedule {
    public:
        Schedule() {}

        void InsertScheduleItem(SchedulingItem k) { schedule_.emplace_back(k); }

        const Schedule &OfTeacher(int id);

        const Schedule OfRoom(int room);

        const Schedule OfYear(int year);

        vector<int> AvailableTimeSlots(int room);

        unsigned long Size() const { return schedule_.size(); }

    private:
        vector<SchedulingItem> schedule_;
    };



    SchedulingItem operator[](const Schedule &S, const int &i) {
        SchedulingItem tmp = schedule_[i];
        return tmp;
    }
}


#endif //JIMP_EXERCISES_SCHEDULER_H
