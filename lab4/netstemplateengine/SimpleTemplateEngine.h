//
// Created by adrian on 26.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;
namespace nets {
    class View {
    public:
        View();

        ~View() {}

        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

        View(string str);



    private:
        string str_;


    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
