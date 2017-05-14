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

#endif //JIMP_EXERCISES_SCHEDULER_H
