//
// Created by Adrian on 2017-05-11.
//

#include "Algo.h"
#include <algorithm>

using namespace std;
namespace algo {
    //test1
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        copy_n(v.begin(), n_elements, back_inserter(*out));
    }
    //test2
    bool Contains(const std::vector<int> &v, int element) {
        if(find(v.begin(), v.end(), element) != v.end()) return true;
    }
    //test 3
    void InitializeWith(int initial_value, std::vector<int> *v){
        fill(v->begin(), v->end(), initial_value);
    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value){
        vector<int>v;
        fill_n(back_inserter(v), length, initial_value);
        return v;
    }
    std::vector<std::string> MapToString(const std::vector<double> &v){
        vector<string>s;
        transform(v.begin(), v.end(), back_inserter(s), [](double i){return to_string(i);});
        return s;
    }
    //test 4
    std::set<std::string> Keys(const std::map<std::string, int> &m){
       /* set<string>s;
        transform(m.begin(), m.end(), back_inserter(s), [](string i){return i;});
        return s;*/
    }
    std::set<std::string> Values(const std::map<std::string, int> &m);
    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key){
        return (v.find(key)!=v.end());
    }
    bool ContainsValue(const std::map<std::string, int> &v, int value){

    }
}