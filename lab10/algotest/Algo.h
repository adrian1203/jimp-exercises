//
// Created by Adrian on 2017-05-11.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H
#include <string>
#include <vector>
#include <set>
#include <map>

    namespace algo{
        //1 test Copy
        void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);
        //test 2
        bool Contains(const std::vector<int> &v, int element);
        //test 3
        void InitializeWith(int initial_value, std::vector<int> *v);
        std::vector<int> InitializedVectorOfLength(int length, int initial_value);
        std::vector<std::string> MapToString(const std::vector<double> &v);
        //test 4
        std::set<std::string> Keys(const std::map<std::string, int> &m);
        std::set<std::string> Values(const std::map<std::string, int> &m);
        bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);
        bool ContainsValue(const std::map<std::string, int> &v, int value);
        
        std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor);
        void SortInPlace(std::vector<int> *v);
        std::vector<int> Sort(const std::vector<int> &v);
        void SortByFirstInPlace(std::vector<std::pair<int,int>> *v);
        void SortBySecondInPlace(std::vector<std::pair<int,int>> *v);
        void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v);
        std::string Join(const std::string &joiner, const std::vector<double> &v);
        int Sum(const std::vector<int> &v);
        int Product(const std::vector<int> &v);
        
        std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v);
        void RemoveDuplicatesInPlace(std::vector<std::string> *v);
        int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length);
    }


#endif //JIMP_EXERCISES_ALGO_H
