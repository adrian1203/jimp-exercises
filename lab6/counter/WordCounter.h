//
// Created by adrian on 06.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <strstream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;
class Word{
private:
    string word_;
public:
    Word();

};
class Counts{
private:
    int value_;
public:
    Counts();

};
class WordCounter{
private:
    std::pair  <Word,Counts> counter_;
    vector <string> pr;
public:
    WordCounter();
    WordCounter(const string& name);

};


#endif //JIMP_EXERCISES_WORDCOUNTER_H
