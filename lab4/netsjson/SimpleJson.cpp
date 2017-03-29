//
// Created by adrian on 24.03.17.
//

#include "SimpleJson.h"
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <regex>

namespace nets {
    using ::std::vector;
    using ::std::map;
    using ::std::cout;
    using ::std::endl;
    using ::std::string;
    using ::nets::JsonValue;
    using ::std::literals::operator ""s;

    JsonValue::JsonValue(int intvalue) {
        intvalue_ = intvalue;
        isInt = 1;
    }

    JsonValue::JsonValue(bool boolvalue) {
        boolvalue_ = boolvalue;
        isBool = 1;
    }

    JsonValue::JsonValue(double doublevalue) {
        doublevalue_ = doublevalue;
        isDouble = 1;
    }

    JsonValue::JsonValue(string str) {
        str_ = str;
        isString = 1;
    }

    JsonValue::JsonValue(const char *text) {
        text_ = text;
        isChar = 1;
    }

    JsonValue::JsonValue(vector<JsonValue> vector1) {
        vector1_ = vector1;
        isVector = 1;
    }

    JsonValue::JsonValue(map<string, JsonValue> mapa) {
        mapa_ = mapa;
        isMap = 1;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        JsonValue tmp;
        for (auto &n:mapa_) {
            if (name == n.first) {
                return std::experimental::make_optional(n.second);
            }
        }
        return {};

    }

    std::string JsonValue::ToString() const {
        std::stringstream stream;
        if (isInt == 1) {
            return std::to_string(intvalue_);
        }
        if (isDouble == 1) {
            stream << doublevalue_;
            string tmp;
            stream >> tmp;
            return tmp;
            return to_string(doublevalue_);
        }
        if (isBool == 1) {
            if (boolvalue_ == true)return "true";
            else return "false";
        }
        if (isString == 1) {
            string tmp = "";
            std::string tmpstr = str_;
            tmp += '\"';
            int j = 0;
            for (int i = 0; i < tmpstr.length(); i++) {
                j = 0;
                if (tmpstr[i] == '\\' or tmpstr[i] == '\"') {
                    tmp += '\\';
                }
                tmp += tmpstr[i];
            }

            tmp += '\"';
            return tmp;
        }
        if (isChar == 1) {
            string tmp = "";
            std::string tmpstr = text_;
            tmp += '\"';
            int j = 0;
            for (int i = 0; i < tmpstr.length(); i++) {
                j = 0;
                if (tmpstr[i] == '\\' or tmpstr[i] == '\"') {
                    tmp += '\\';
                }
                tmp += tmpstr[i];
            }

            tmp += '\"';
            return tmp;
        }
        if (isVector == 1) {
            std::string tmp = "[";
            for (auto &n:vector1_) {
                tmp += n.ToString();
                tmp += ", ";
            }
            tmp.erase(tmp.length() - 2, 2);
            tmp += "]";
            return tmp;
        }
        if (isMap == 1) {
            string tmp;
            string tmp1;
            tmp += '{';
            for (auto n : mapa_) {
                tmp += "\"";
                for (int i = 0; i < n.first.length(); i++) {
                    if (n.first[i] == '\\' or n.first[i] == '\"') {
                        tmp += "\\";
                    }
                    if (n.first[i] == '\"') {
                        tmp += "\"";
                    }
                    else {
                        tmp += n.first[i];
                    }
                }
                tmp += "\": ";
                tmp += n.second.ToString();
                tmp += ", ";
            }
            tmp.erase(tmp.length() - 2, 2);
            tmp += '}';
            return tmp;
        }
        return "";
    }
}
