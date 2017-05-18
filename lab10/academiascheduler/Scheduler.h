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
#include <experimental/optional>
#include <map>
#include <set>
#include <stdexcept>

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

        vector<SchedulingItem> GetSchedule() { return schedule_; }

        size_t Size() const;

        SchedulingItem operator[](int id) const;


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

//tylko wirualna
    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) =0;
    };

    class GreedyScheduler : public Scheduler {
    public:
        GreedyScheduler() {};

        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };

    class NoViableSolutionFound : public runtime_error {
    public:
        NoViableSolutionFound() : runtime_error("error") {}
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
