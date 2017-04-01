//
// Created by adrian on 30.03.17.
//

#include "TextPool.h"
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <iostream>
using namespace std;
namespace pool{
    TextPool::TextPool(const std::initializer_list<std::string> &elements){
        for (const string &n :elements) {
            if (set_.find(n) != set_.end()) {}
            else {
                set_.emplace(n);
            }
        }
    }
    std::experimental::string_view TextPool:: Intern(const std::string &str){
        //int lenght=counter_.size();
        int i=0;
        for(auto n:set_){
            if(n==str){
                return n;
            }
        }
        set_.insert(str);
        for(auto n:set_){
            if(n==str){
                return n;
            }
        }

    }
    size_t TextPool::StoredStringCount() const{
        return set_.size();
    }
    //pierwszy
    /*TextPool::TextPool(const TextPool &other) {
        set_.operator=(other.set_);
    }*/


}
