//
// Created by Adrian on 2017-05-01.
//

#include "MovieSubtitles.h"

using namespace std;
namespace moviesubs {
    bool Check_number(const char &x) {
        string numbers = "0123456789";
        for (int i = 0; i < 10; i++) {
            if (numbers[i] == x) return true;
        }
        return false;
    }
    int SubtitleEndBeforeStart::LineAt() const {
        return value_line_;
    }

    void SubRipSubtitles::IfNegative(int delay, int framerate) {
        if(delay < 0 || framerate < 0) throw NegativeFrameAfterShift();
    }
    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, stringstream *in, stringstream *out) {
        string changed_text;
        changed_text = (*in).str();
        int seconds, miliseconds;
        IfNegative(delay,framerate);

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
    }

    //bledy do micordvd


    std::string ReturnLineWithError(int i, std::stringstream *in) {
        i=i+1;
        string tmp_text=(*in).str();
        string text;

        while (tmp_text[i] != '\n') {
            text += tmp_text[i];
            i++;
        }
        return text;
    }


    void
    MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out) {
        if (framerate <= 0) throw WrongFramerateException(framerate);
        if (delay < 0) throw NegativeFrameAfterShift();
        string changed_text, tmp_fre;
        int tmp1;
        pair<int, int> line;
        line.first++;
        changed_text = (*in).str();
        int lenght = changed_text.length();
        for (int i = 0; i < lenght; i++) {
            if (changed_text[i] == '\n') {
                line.first++;
                line.second = i;
            }
            if (changed_text[i] == '}') throw InvalidSubtitleLineFormat();
            if (changed_text[i] != '{') {
                *out << changed_text[i];
            } else {
                i++;
                tmp_fre.clear();
                if (changed_text[i] == '}') {
                    throw InvalidSubtitleLineFormat();
                }
                while (changed_text[i] != '}') {
                    if (!Check_number(changed_text[i]))throw InvalidSubtitleLineFormat();
                    tmp_fre += changed_text[i];
                    i++;
                }
                tmp1 = atoi(tmp_fre.c_str());
                if (tmp1 < 0) {
                    throw NegativeFrameAfterShift();
                }
                i++;
                tmp_fre.clear();

                if (changed_text[i] != '{') {
                    throw InvalidSubtitleLineFormat();
                }
                i++;
                if (changed_text[i] == '}') {
                    throw InvalidSubtitleLineFormat();
                }
                while (changed_text[i] != '}') {
                    if (!Check_number(changed_text[i]))throw InvalidSubtitleLineFormat();
                    tmp_fre += changed_text[i];
                    i++;
                }

                if (tmp1 >= atoi(tmp_fre.c_str())) {
                    throw SubtitleEndBeforeStart(line, in);
                }
                if (atoi(tmp_fre.c_str()) < 0) {
                    throw NegativeFrameAfterShift();
                }
                *out << '{' + to_string(tmp1 + (framerate * delay) / 1000) + '}' + '{' +
                        to_string(atoi(tmp_fre.c_str()) + (framerate * delay) / 1000) + '}';
                if (changed_text[i + 1] == '{') {
                    *out << '{';
                    i = i + 2;
                    while (changed_text[i] != '}') {
                        *out << changed_text[i];
                        i++;
                    }
                    *out << '}';
                }
            }

        }
        if (changed_text[lenght - 1] != '\n') {
            *out << '\n';
        }
    }



}