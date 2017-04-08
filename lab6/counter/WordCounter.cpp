//
// Created by adrian on 06.04.17.
//

#include "WordCounter.h"
#include <iostream>
WordCounter::WordCounter() {
    pr=;
    counter_.first=(Word());
    counter_.second=(Counts());
}
Word::Word() {
    word_="";
}
Counts::Counts() {
    value_=0;
}
void WordCounter::WordCounter(const string& name)
{
    vector<string> tmp1;
    ifstream infile;
    infile.open(name);
    if(infile.good())
    {
        string word;
        while(infile>>word) {
            tmp1.push_back(word);
        }
    }
    for (const string &n :tmp1) {
        Word tmp1(n);
        counter_.first=tmp1;

    }
}


};
