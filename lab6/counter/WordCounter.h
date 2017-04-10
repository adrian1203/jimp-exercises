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
#include <list>
#include <set>

using namespace std;
namespace datastructures {
    class Word {
    private:
        string word_;
    public:
        Word();

        Word(const string &word);

        bool operator==(const Word &other_object) const;

        bool operator<(const Word &other) const;

        bool operator>(const Word &other) const;

        string GetWord(void) const;

        friend class WordCounter;
    };

    class Counts {
    private:
        int value_;
    public:
        Counts();

        Counts(int value);

        Counts &operator++(int);

        operator int() const;

        bool operator<(const Counts &other) const;

        bool operator>(const Counts &other) const;

        friend bool operator==(const int int_value, const Counts &other_object);

        int GetCounts(void) const;

    };

    class WordCounter {
    private:
        list <pair<Word, Counts>> counter_;
    public:
        WordCounter();

        WordCounter(const char *file);

        WordCounter(const initializer_list<Word> list1);

        int DistinctWords();

        int TotalWords();

        Counts operator[](const char *word);

        set<Word> Words(void) const;

        friend ostream &operator<<(std::ostream &is, WordCounter &word_counter);


    };

    ostream &operator<<(std::ostream &is, WordCounter &word_counter);

    bool operator==(const int int_value, const Counts &other_object);

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
