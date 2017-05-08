//
// Created by adrian on 02.05.2017.
//
#include "MovieSubtitles.h"
#include <vector>
#include <iostream>

namespace moviesubs{


    void MovieSubtitles::ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out) {}
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out) {

        int delay,integertmp;
        string workingon,tmp,replacment,res;
        vector<int> begin,end,time;
        bool type;
        type= true;
        delay=first*second/1000;
        if (first<0 ) throw NegativeFrameAfterShift();
        if (second<0) throw invalid_argument("error");
        workingon=in->str();
        for (int i = 0; i <workingon.size() ; i++) {
            if (workingon[i] == '{') {
                begin.emplace_back(i+1);}
            if (workingon[i] == '}') {
                end.emplace_back(i-1);
            }
        }
        //  if ((begin.size()!=end.size() or (begin.size()+end.size())%2!=0)or begin.size()%2!=0 or end.size()%2!=0) throw InvalidSubtitleLineFormat();
        for (int j = 0; j <begin.size() ; j++) {
            tmp=workingon.substr(begin[j],end[j]-begin[j]+1);
            for (int l = 0; l <tmp.size() ; l++) {
                if((int(tmp[l])<48 or int(tmp[l])>57) ) type= false ;

            }

            if ((type== false and tmp.find(':')>tmp.size()) or tmp.size()==0) throw  InvalidSubtitleLineFormat();
            if (type) {
                integertmp = stoi(tmp) + delay;
                time.emplace_back(stoi(tmp));

                replacment = to_string(integertmp);



                workingon.replace(begin[j], replacment.size(), replacment);
                if (replacment.size() > tmp.size()) {
                    for (int i = j; i < begin.size(); i++) {
                        begin[i]++;
                        end[i]++;

                    }
                    workingon.insert(begin[j]+replacment.size()-1,"}");
                }


            }
            type= true;

        }
        if (time.size()%2==1) throw InvalidSubtitleLineFormat();
        if (time.size()%2==0){

            for (int k = 0; k <time.size()-1 ; k+=2) {

                if (time[k]>time[k+1]) throw SubtitleEndBeforeStart(((k+1)/2)+1,in->str(),"micro");


            }
        }
        if (workingon[workingon.size()-1]!='\n') workingon+='\n';

        out->clear();

        (*out)<<workingon;

    }

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int i,string sub, string micorsub) {
        line=i;
        string1=sub;
        mos=micorsub;
    }
    int SubtitleEndBeforeStart::LineAt()const {
        return line;
    }
    string SubtitleEndBeforeStart::what() const {
        int currentline=1;
        string linetext,result;
        if (mos=="micro"){
            while (currentline<line+1){
                for (int i = 0; i <string1.size() ; i++) {
                    if (string1[i] == '\n') {
                        currentline++;
                        i++;
                    }
                    if (currentline > line) break;
                    if (currentline == line) linetext += string1[i];


                }
            }
        }
        if (mos=="sub") linetext=string1;
        result="At line " +to_string(line) +": "+linetext;
        return result;
    }
    bool Check_number(const char &x) {
        string numbers = "0123456789";
        for (int i = 0; i < 10; i++) {
            if (numbers[i] == x) return true;
        }
        return false;
    }


    void SubRipSubtitles::ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out) {
        int delay=first;
        vector<int>positon,lnum;
        string subtitles=(*in).str();
        vector<string> times;
        string changed_text,tmp="";
        changed_text = (*in).str();
        int seconds, miliseconds,linenumber=1,lnumit=1,min[2],sec[2],hour[2];

        bool chek= true;
        lnum.emplace_back(1);
        for (int k = 2; k <subtitles.size() ; k++) {
            if (subtitles.find("\n"+to_string(k)+"\n")<=subtitles.size()) lnum.emplace_back(k);


        }
        lnum.shrink_to_fit();
        for (int j = 0; j <lnum.size()-1 ; ++j) {
            if (lnum[j]!=lnum[j+1]-1) throw OutOfOrderFrames();
        }
        if (first<0 ) throw NegativeFrameAfterShift();
        if (second<0) throw invalid_argument("error");


        for (int i = 0; i <subtitles.size() ;i++) {
            if(subtitles[i]=='>') {

                positon.emplace_back(i);
            }
        }

        for (auto &n:positon) {

            min[0]=stoi(subtitles.substr(n-12,2));
            min[1]=stoi(subtitles.substr(n+5,2));
            sec[0]=stoi(subtitles.substr(n-9,2));
            sec[1]=stoi(subtitles.substr(n+8,2));
            if(min[0]>min[1] or(min[0]<min[1] and sec[0]>sec[1])) throw SubtitleEndBeforeStart(linenumber,subtitles.substr(n-15,29),"sub");
            linenumber++;
            if (subtitles.substr(n-3,5)!=" --> ") throw InvalidSubtitleLineFormat();
            if (subtitles[n+4]!=':' or subtitles[n+7]!=':' or subtitles[n-10]!=':' or subtitles[n-13]!=':') throw InvalidSubtitleLineFormat();
            if( subtitles[n+10]!=',' or  subtitles[n-7]!=',' ) throw InvalidSubtitleLineFormat();

        }
        if (lnum.size()!=positon.size()) throw InvalidSubtitleLineFormat();


        for (int i = 0; i < changed_text.length(); i++) {
            if ((changed_text[i] == '\n' and Check_number(changed_text[i + 1])) or
                (changed_text[i] == '-' and changed_text[i + 1] == '-')) {
                seconds = 0;
                miliseconds = 0;
                while (changed_text[i + 3] != ',') {
                    *out << changed_text[i];
                    i++;
                }

                seconds = (changed_text[i + 1] - 48) * 10 + changed_text[i + 2] - 48;
                i += 3;
                miliseconds =
                        (changed_text[i + 1] - 48) * 100 + (changed_text[i + 2] - 48) * 10 + changed_text[i + 3] - 48;
                i += 3;
                *out << ':';
                if (miliseconds + delay > 1000) {

                    seconds = seconds + (delay + miliseconds) / 1000;
                    miliseconds = (delay + miliseconds) % 1000;

                    if (seconds < 10) {
                        *out << '0' + to_string(seconds) + ',' + to_string(miliseconds);
                    } else if (miliseconds < 10) {
                        *out << to_string(seconds) + ",00" + to_string(miliseconds);
                    } else if (miliseconds < 100) {
                        *out << to_string(seconds) + ",0" + to_string(miliseconds);
                    } else *out << to_string(seconds) + ',' + to_string(miliseconds);

                } else {
                    if (seconds < 10) {
                        *out << '0' + to_string(seconds) + ',' + to_string(delay + miliseconds);
                    } else if (miliseconds < 10) {
                        *out << to_string(seconds) + ",00" + to_string(delay + miliseconds);
                    } else if (miliseconds < 100) {
                        *out << to_string(seconds) + ",0" + to_string(delay + miliseconds);
                    } else *out << to_string(seconds) + ',' + to_string(delay + miliseconds);

                }
            } else *out << changed_text[i];
        }
        if (changed_text[changed_text.size()-2]!='\n') *out<<'\n';

    }
}