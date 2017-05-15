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
#include <experimental/optional>
#include <map>
#include <set>

using namespace std;
namespace academia {
    class SchedulingItem;

    class Schedule {
    public:
        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](int id) const;

        vector<SchedulingItem> GetSchedule() { return schedule_; }

    private:
        vector<SchedulingItem> schedule_;
    };

    class SchedulingItem {
    public:
        SchedulingItem(int course, int teacher, int room, int time, int year) :
                course_id_{course}, teacher_id_{teacher}, room_id_{room},
                time_slot_{time}, year_{year} {}

        int CourseId() const { return course_id_; };

        int TeacherId() const { return teacher_id_; };

        int RoomId() const { return room_id_; };

        int TimeSlot() const { return time_slot_; };

        int Year() const { return year_; };


    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    };

    class Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };
    class GreedyScheduler{

    };
    class NoViableSolutionFound{

    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
