//
// Created by adrian on 14.03.17.
//

#include "MinimalTimeDifference.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;
namespace minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM) {

        regex pattern{R"((\d{1,2}+):+(\d{2}))"};
        smatch matches;
        regex_match(time_HH_MM, matches, pattern);
        int h1 = stoi(matches[1]);
        int h2 = stoi(matches[2]);
        int minutes = 60 * h1 + h2;
        return minutes;

    }
unsigned int MinimalTimeDifference(std::vector<std::string> times){
    int n = times.size();
    int *tab = new int[n];
    for (int i = 0; i < n; i++) {

        tab[i] = ToMinutes(times[i]);
    }
    int diference = 1440;
    for (int i = 0; i < n; i++) {
        int tmp = tab[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int l1 = abs(tmp - tab[j]);
                if (l1 < diference) {
                    diference = abs(l1);
                }
                int l2 = abs(l1 - 1440);
                if (l2 < diference) {
                    diference = l2;
                }
            }
        }
    }
    delete[] tab;
    return diference;
}}


