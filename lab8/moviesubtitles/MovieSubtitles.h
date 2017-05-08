//
// Created by adrian on 02.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <vector>

using  namespace std;
namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out) override;


    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int first, int second, stringstream *in, stringstream *out) override;

    };

    class NegativeFrameAfterShift{

    };

    /*class SubtitleEndBeforeStart {
        int line;
        string string1;
    public:
        SubtitleEndBeforeStart(int i,string sub);

        int LineAt()const;
        string what()const;
    };
     */
    class SubtitleEndBeforeStart: public std::runtime_error{
    public:
        SubtitleEndBeforeStart() = delete;
        SubtitleEndBeforeStart(std::string str, int line):std::runtime_error("At line " + std::to_string(line) + ": " +
                                                                          str),line_(line){};
        int LineAt () const {return line_;}
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat {};
    class MissingTimeSpecification{};
    class OutOfOrderFrames{};
    bool Check_number(const char &x);

};
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H