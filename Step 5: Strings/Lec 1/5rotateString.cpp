#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(s.length()!=goal.length()) return false;
        string strDouble = s + s;
        return strDouble.find(goal)!=string::npos;
    }
};