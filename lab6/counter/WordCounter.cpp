//
// Created by adrian on 06.04.17.
//

#include "WordCounter.h"
#include <iostream>

namespace datastructures {
    WordCounter::WordCounter() {
    }

    Word::Word() {
        word_ = "";
    }

    Word::Word(const string &word) {
        word_ = word;
    }

    bool Word::operator==(const Word &other) const {
        if (this->word_ == other.word_) {
            return true;
        }
        return false;
    }

    bool Word::operator<(const Word &other) const {
        if (this->word_ < other.word_) {
            return true;
        }
        return false;
    }

    bool Word::operator>(const Word &other) const {
        if (this->word_ > other.word_) {
            return true;
        }
        return false;
    }

    std::string Word::GetWord(void) const {
        return this->word_;
    }

    Counts::Counts() {
        value_ = 0;
    }

    Counts::Counts(int value) {
        value_ = value;
    }

    Counts &Counts::operator++(int) {
        this->value_++;
        return *this;
    }

    Counts::operator int() const {
        return this->value_;
    }

    bool Counts::operator<(const Counts &other) const {
        if (this->value_ < other.value_) {
            return true;
        }
        return false;
    }

    bool Counts::operator>(const Counts &other) const {
        if (this->value_ > other.value_) {
            return true;
        }
        return false;
    }

    bool operator==(const int int_value, const Counts &other) {
        if (other.value_ == int_value) {
            return true;
        }
        return false;
    }

    int Counts::GetCounts(void) const {
        return this->value_;
    }

    WordCounter::WordCounter(const char *file) {
        ifstream file_open;
        file_open.open(file);
        if (file_open.good()) {
            string word = "";
            string tmpstr = "";
            while (file_open >> word) {
                tmpstr = "";
                for (char c:word) {
                    if (c >= 65 and c <= 90) {
                        c += 32;
                    }
                    if (c >= 97 and c <= 122) {
                        tmpstr.push_back(c);
                    }
                }
                Word tmp_word(tmpstr);
                bool is_word = false;
                for (pair<Word, Counts> &n: this->counter_) {
                    if (tmp_word == n.first) {
                        n.second++;
                        is_word = true;
                        break;
                    }
                }
                if (is_word == false) {
                    this->counter_.push_front(pair<Word, Counts>{tmp_word, Counts(1)});
                }
            }
            this->counter_.sort();
        }
        return;
    }

    WordCounter::WordCounter(const std::initializer_list<Word> list1) {
        string tmpstr = "";
        for (Word word: list1) {
            bool is_word = false;
            for (pair<Word, Counts> &n: this->counter_) {
                if (word == n.first) {
                    n.second++;
                    is_word = true;
                }
            }
            if (is_word == false) {
                this->counter_.push_back(pair<Word, Counts>{word, Counts(1)});
            }

        }
        this->counter_.sort();
    }

    int WordCounter::DistinctWords() {
        return this->counter_.size();
    }

    int WordCounter::TotalWords() {
        if (!counter_.empty()) {

            int tmp_value;
            for (pair<Word, Counts> &n: this->counter_) {
                tmp_value += n.second;
            }
            return tmp_value;
        } else {
            return 0;
        }
    }

    Counts WordCounter::operator[](const char *word) {
        if (!this->counter_.empty()) {
            int result = 0;
            string tmp(word);
            for (pair<Word, Counts> &n: this->counter_) {
                if (n.first == tmp) {
                    result = n.second;
                }
            }
            return Counts(result);
        } else {
            return Counts{};
        }
    }

    set<Word> WordCounter::Words(void) const {
        set<Word> set1;
        if (!(this->counter_.empty())) {
            for (pair<Word, Counts> n: this->counter_) {
                set1.insert(n.first);
            }
            return set1;
        } else {
            return set1;
        }
    }

    std::ostream &operator<<(std::ostream &is, WordCounter &counter) {
        list<pair<Word, Counts>>::reverse_iterator iterator1;
        /* for(list<pair<Word,Counts>>n: &counter){
             is << n.first.GetWord();
             is<<" ";
             is<<n.second.GetCounter();
             is<<"\n";
         }*/
        for (iterator1 = counter.counter_.rbegin(); iterator1 != counter.counter_.rend(); iterator1++) {
            is << iterator1->first.GetWord();
            is << " ";
            is << iterator1->second.GetCounts();
            is << "\n";

        }
        return is;
    }

};

