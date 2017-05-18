//
// Created by Adrian on 2017-04-26.
//

#include "Pesel.h"
namespace academia{
    Pesel::Pesel(const char *in) {
        validatePESEL(in);
    }

    void Pesel::validatePESEL(const char *in) {
        if(PeselLength(in)){
            throw InvalidPeselLength();
        }
        else if(PeselCharacter(in)){
            throw InvalidPeselCharacter();
        }
        else if(PeselChecksum(in)){
            throw InvalidPeselChecksum();
        }

    }

    bool Pesel::PeselChecksum(const char *in) {
        int suma = 0;
        suma = 9*((int)in[0]-48)+7*((int)in[1]-48)+3*((int)in[2]-48)+1*((int)in[3]-48)+
               9*((int)in[4]-48)+7*((int)in[5]-48)+3*((int)in[6]-48)+1*((int)in[7]-48)+9*((int)in[8]-48)+7*((int)in[9]-48);
        if(suma%10 != ((int)in[10]-48)){
            return true;
        } else{
            return false;
        }
    }

    bool Pesel::PeselLength(const char *in) {
        int i = 0;
        while(in[i] != '\0'){
            i++;
        }
        if(i != 11){
            return true;
        } else{
            return false;
        }
    }

    bool Pesel::PeselCharacter(const char *in) {
        int i = 0;
        while(in[i] != '\0'){
            if(in[i] < 48 or in[i] > 39){
                return true;
            }
        }
        return false;
    }

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &pesel, int checksum) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)) {
       //message_ = "Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum);

    }

    InvalidPeselLength::InvalidPeselLength(const std::string &pesel, int length) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " + std::to_string(length)){
       // message_ = ;
    }

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &pesel) : AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set"){
        //message_ = "Invalid PESEL(" + pesel + ") character set";
    }


}