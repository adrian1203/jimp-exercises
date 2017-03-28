//
// Created by adrian on 24.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
namespace nets{
    class JsonValue{
    public:
        JsonValue(){}
        ~JsonValue(){}
        JsonValue(int intvalue);
        JsonValue(double doublevalue);
        JsonValue(string str );
        JsonValue(const char *);
        JsonValue(bool boolvalue);
        JsonValue(vector <JsonValue> vector1);
        JsonValue(map <string, JsonValue> mapa);
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        int intvalue_;
        double doublevalue_;
        string str_;
        bool boolvalue_;
        vector <JsonValue> vector1_;
        map <string, JsonValue> mapa_;
        const char *text_;

        int isInt=0;
        int isDouble=0;
        int isString=0;
        int isBool=0;
        int isVector=0;
        int isMap=0;
        int isChar=0;


    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
