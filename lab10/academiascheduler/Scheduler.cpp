//
// Created by Adrian on 2017-05-13.
//
#include "Scheduler.h"
#include <algorithm>
using namespace std;
namespace academia{


    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedule_.emplace_back(item);
    }
    size_t Schedule::Size() const {
        return schedule_.size();
    }
    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        /*bool Foo(SchedulingItem n){
            return (n.TeacherId()==teacher_id);
        }*/
        for(auto n:schedule_){
            if(n.TeacherId()==teacher_id){
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
       // copy_if(schedule_.begin(), schedule_.end(),tmp, [] (SchedulingItem i) -> bool { return i.TeacherId()==1;});
    }
    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        for(auto n:schedule_){
            if(n.RoomId()==room_id){
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }
    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        for(auto n:schedule_){
            if(n.Year()==year){
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }
    vector <int >Schedule::AvailableTimeSlots(int n_time_slots) const {
        bool if_is;
        vector<int> freetime;
        for (int i=1;i<=n_time_slots;i++) {
            if_is = true;
            for (auto n:schedule_) {
                if (n.TimeSlot() == i)
                    if_is = false;
            }
            if (if_is)
                freetime.emplace_back(i);
        }
        return freetime;
    }

    SchedulingItem Schedule::operator[](int id) const {
        int i=0;
        for(auto n:schedule_){
            if(i==id){
                return n;
            }
            i++;
        }
    }



}

