//
// Created by adrian on 24.03.17.
//

#include "SimpleJson.h"
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
namespace nets{
    using ::std::vector;
    using ::std::map;
    using ::std::cout;
    using ::std::endl;
    using ::std::string;
    using ::nets::JsonValue;
    using ::std::literals::operator""s;
    JsonValue::~JsonValue() {}
    JsonValue::JsonValue() {}
    JsonValue::JsonValue(int intvalue) {
        intvalue_=intvalue;
    }
    JsonValue::JsonValue(bool boolvalue) {
        boolvalue_=boolvalue;
    }
    JsonValue::JsonValue(double doublevalue) {
        doublevalue_=doublevalue;
    }
    JsonValue::JsonValue(string str) {
        str_=str;
    }
    JsonValue::JsonValue(vector<JsonValue> vector1) {
        vector1_=vector1;
    }
    JsonValue::JsonValue(map<string, JsonValue> mapa) {
        mapa_=mapa;
    }
}
