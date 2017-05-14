//
// Created by Adrian on 2017-05-13.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
namespace academia {
    class SchedulingItem;

    class Schedule {
    public:
        Schedule() {}

        void InsertScheduleItem(SchedulingItem k) { schedule_.emplace_back(k); }

        Schedule &OfTeacher(int teacherid);

        const Schedule OfRoom(int room);

        const Schedule OfYear(int room);

        std::vector<int> AvailableTimeSlots(int room);

        unsigned long Size() const { return schedule_.size(); }
        //Schedule(vector<SchedulingItem> schedule);
    private:
        vector<SchedulingItem> schedule_;
    };

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

    SchedulingItem operator[](const Schedule &S, const int &i) {
        SchedulingItem POINTER = schedule_[i];
        return POINTER;
    }
}


#endif //JIMP_EXERCISES_SCHEDULER_H
