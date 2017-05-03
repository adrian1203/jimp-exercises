//
// Created by Adrian on 2017-05-01.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

using namespace std;
namespace moviesubs {

    class MovieSubtitles {
    public:
        MovieSubtitles() {};

        ~MovieSubtitles() {};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out) {};

    };


    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles() : MovieSubtitles() {};
        void IfNegative(int delay, int framerate);
        ~SubRipSubtitles() {};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() : MovieSubtitles() {};

        ~MicroDvdSubtitles() {};

        virtual void ShiftAllSubtitlesBy(int delay, int framerate, std::stringstream *in, std::stringstream *out);


    };

    /*exception*/
    class MovieSubtitlesError : public std::runtime_error {
    public:
        MovieSubtitlesError(string error_message) : runtime_error(error_message) {};

        //virtual ~MovieSubtitlesError() {};
    };

    class NegativeFrameAfterShift : public MovieSubtitlesError {
    public:
        NegativeFrameAfterShift() : MovieSubtitlesError{"Negative error"} {};

        ~NegativeFrameAfterShift() {};
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesError {
    public:
        InvalidSubtitleLineFormat() : MovieSubtitlesError("Invalid error") {};

        //~InvalidSubtitleLineFormat() {};
    };

    class WrongFramerateException : public std::invalid_argument {
    public:
        WrongFramerateException(const int &framerate) : invalid_argument{"Framerate error "}, framerate_{framerate} {};
        int framerate_;
        //~WrongFramerateException(){};

    };

    string ReturnLineWithError(int line, stringstream *in);

    class SubtitleEndBeforeStart : public MovieSubtitlesError {
    public:
        SubtitleEndBeforeStart(const pair<int, int> &line, stringstream *in) :
                value_line_{line.first},
                MovieSubtitlesError(
                        "At line " + to_string(line.first) + ": " + ReturnLineWithError(line.second, in)) {};
        //~SubtitleEndBeforeStart(){};
        int value_line_;

        int LineAt() const;
    };
    class MissingTimeSpecification : public MovieSubtitlesError{
    public:
        MissingTimeSpecification() :  MovieSubtitlesError("Missing "){};
        ~MissingTimeSpecification(){};
    };

    class OutOfOrderFrames : public MovieSubtitlesError{
    public:
        OutOfOrderFrames() :  MovieSubtitlesError("Out "){};
        ~OutOfOrderFrames(){};
    };

}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
