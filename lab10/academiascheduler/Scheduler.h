//
// Created by Adrian on 2017-05-13.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
namespace academia{
    class SchedulingItem;
    class Schedule{
    public:
        //Schedule(vector<SchedulingItem> schedule);
        void InsertScheduleItem(SchedulingItem v);
        Schedule OfTeacher(int id);
    private:
        vector<SchedulingItem> schedule_;
    };
    class SchedulingItem{
    public:
        SchedulingItem(initializer_list<int> v);
        int CourseId();
        int TeacherId();
    private:
        int scheduling_[5];
    };
}
*/
#include <vector>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <list>
#include <array>
#include <memory>

namespace academia {


    class SchedulingItem {
    public:
        SchedulingItem(std::initializer_list<unsigned long> it) {
            std::copy(it.begin(),it.end(),item.begin());
        }

        unsigned long CourseId() const { return  item[0];}
        unsigned long TeacherId() const { return item[1];}
        unsigned long RoomId() const { return item[2];}
        unsigned long TimeSlot() const { return item[3];}
        unsigned long Year() const { return item[4];}

    private:
        std::vector<unsigned long> item;
    };


    class Schedule {
    public:
        Schedule() {}

        void InsertScheduleItem(SchedulingItem k) { schedules.emplace_back(k); }

        Schedule &OfTeacher(int teacherid);
        const Schedule OfRoom(int room);
        const Schedule OfYear(int room);
        std::vector<int> AvailableTimeSlots(int room);

        unsigned long Size() const { return schedules.size(); }

    private:
        std::vector<SchedulingItem> schedules;
    };

    SchedulingItem operator[](const Schedule &S, const int &i) {
        SchedulingItem POINTER = schedules[i];
        return POINTER;
    }
}
#endif //JIMP_EXERCISES_SCHEDULER_H
