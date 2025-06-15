#include <iostream>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> ms;
        std::unordered_map<char, int> mt;

        for(const auto &ele : s){
            ms[ele]++;
        }
    
        for(const auto &ele : t){
            mt[ele]++;
        }

        return ms==mt;

    }
};