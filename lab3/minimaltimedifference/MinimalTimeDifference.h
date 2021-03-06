//
// Created by adrian on 14.03.17.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#include <vector>
#include <iostream>
#include <string>
#include <regex>

namespace minimaltimedifference {

    unsigned int ToMinutes(std::string time_HH_MM);
    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}

#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
