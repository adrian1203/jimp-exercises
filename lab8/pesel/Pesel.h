//
// Created by Adrian on 2017-04-26.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H
#include <stdexcept>
using namespace std;
namespace academia {
    class Pesel {
    public:
        Pesel(const char *in);
        static void validatePESEL(const char *in);
        static bool PeselChecksum(const char *in);
        static bool PeselLength(const char *in);
        static bool PeselCharacter(const char *in);

    };

    class AcademiaDataValidationError : public runtime_error{
    public:
        AcademiaDataValidationError(string message) : runtime_error(message){

        }

    private:
        string message_;
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const string &pesel="100" , int checksum = 0);
    private:
        string message_;
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const string &pesel = "123", int length = 0);
    private:
        string message_;
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const string &pesel = "123");
    private:
        string message_;
    };



}

#endif //JIMP_EXERCISES_PESEL_H

