//
// Created by Adrian on 2017-05-13.
//
#include "Scheduler.h"
#include <algorithm>

using namespace std;
namespace academia {


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
        for (auto n:schedule_) {
            if (n.TeacherId() == teacher_id) {
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
        // copy_if(schedule_.begin(), schedule_.end(),tmp, [] (SchedulingItem i) -> bool { return i.TeacherId()==1;});
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        for (auto n:schedule_) {
            if (n.RoomId() == room_id) {
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        for (auto n:schedule_) {
            if (n.Year() == year) {
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }

    vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        int if_is = 1;
        vector<int> freetime;
        for (int i = 1; i <= n_time_slots; i++) {
            if_is = true;
            for (auto n:schedule_) {
                if (n.TimeSlot() == i)
                    if_is = 0;
            }
            if (if_is != 0)
                freetime.emplace_back(i);
        }
        return freetime;
    }

    SchedulingItem Schedule::operator[](int id) const {
        int i = 0;
        for (auto n:schedule_) {
            if (i == id) {
                return n;
            }
            i++;
        }
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule schedule;
        //pętle w pętli iteruje rocznikami, nastpenie zajęcie, room itd...
        for (auto &years : courses_of_year) {
            set<int> t_years;
            for (int i = 1; i <= n_time_slots; i++) {
                t_years.emplace(i);     // tworze wolne godziny jako set,
            }
            //pętle po kursach jakie ma dany rok
            for (auto it_c : years.second) {
                map<int, set<int>> teachers;
                for (const pair<int, vector<int>> &n : teacher_courses_assignment) {
                    vector<int>::const_iterator it = find(n.second.begin(), n.second.end(),
                                                          it_c);
                    if (it != n.second.end()) {
                        teachers.insert(pair<int, set<int>>(n.first, {/*pusty...*/}));
                    }
                }
                for (auto &m :teachers) {
                    vector<int> time_t = schedule.OfTeacher(
                            m.first).AvailableTimeSlots(n_time_slots);
                    set<int> tmp;
                    for (int k : t_years) {
                        for (int n : time_t) {
                            if (n == k) {
                                tmp.emplace(k);
                            }
                        }
                    }
                    if (tmp.empty() == 0) {
                        teachers.find(m.first)->second = tmp; //wsk..
                    } else {
                        teachers.erase(m.first);
                    }
                }
                if (teachers.empty() != 0) {
                    throw NoViableSolutionFound();//Brak nuaczycieli dla tego rocznika...
                }
                //cout<<"nie wyrzucił "
                for (auto &n:teachers) {
                    int grups = 0;
                    for (int id_course : teacher_courses_assignment.find(n.first)->second) {
                        if (it_c == id_course) {
                            grups += 1;
                        }
                    }
                    //cout<<"Dochodze tu"
                    if (n.second.size() < grups) {
                        throw NoViableSolutionFound();//chyba dlatego wyrzucało, chociaż nie wiem xd
                    }
                    for (int m : rooms) {
                        vector<int> rooms_av = schedule.OfRoom(m).AvailableTimeSlots(
                                n_time_slots);
                        set<int> rooms;
                        for (int k : rooms_av) {
                            if (n.second.find(k) != n.second.end()) {
                                rooms.emplace(k);//problem z push
                            }
                        }
                        for (int l : rooms) {
                            if (0 >= grups) {
                                break;//.............i od razu 3 testy wiecej....:).....
                            }
                            grups = grups - 1; // jedna grupa już mniej
                            t_years.erase(l);
                            schedule.InsertScheduleItem(
                                    SchedulingItem{it_c, n.first, m,
                                                   l, years.first});
                            for (map<int, set<int>>::iterator i = teachers.begin(); i != teachers.end(); i++) {
                                i->second.erase(l); //dziwne  ale działa ... chyba
                            }
                        }
                    }
                    if (grups > 0) {
                        throw NoViableSolutionFound();//sprawdzić czy to to...
                    }
                }
            }
        }
        return schedule;
    }
}


