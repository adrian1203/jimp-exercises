//
// Created by Adrian on 2017-05-13.
//

/*#include "Scheduler.h"
#include <algorithm>
using namespace std;
namespace academia{
    SchedulingItem::SchedulingItem(initializer_list<int> v){
        int i=0;
        for(auto n:v){
            scheduling_[i]=n;
            i++;
        }
    }
    /*Schedule::Schedule(vector<SchedulingItem> schedule) {
        copy(schedule.begin(), schedule.end(), schedule_);
    }
    void Schedule::InsertScheduleItem(SchedulingItem v) {
        schedule_.push_back(v);
    }
    Schedule Schedule::OfTeacher(int id) {
        Schedule tab[10];
        int i=0;
        for(auto n:schedule_){
            if(n.TeacherId()==1){
                tab[i]=n;
                i++;
            }
        }
        return tab;
    }
}*/
#include "Scheduler.h"

namespace academia{

    Schedule &Schedule::OfTeacher(int teacherid) {
        Schedule teacher;
        for (int i = 0; i < schedules.size(); ++i) {
            if (schedules[i].TeacherId() == teacherid) {
                teacher.InsertScheduleItem(schedules[i]);
            }
        }
        return this;
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
