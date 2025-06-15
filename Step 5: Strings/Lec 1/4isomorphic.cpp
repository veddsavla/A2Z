#include <iostream>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        map<char, char> charMap;
        map<char, char> reverseMap; // To check if target char is already mapped
        
        for(int i = 0; i < s.length(); i++) {
            char og = s[i];        // Use [] instead of charAt
            char rep = t[i];       // Use [] instead of charAt
            
            // Check if original character is already mapped
            if(charMap.find(og) == charMap.end()) {
                // Original char not mapped yet
                // Check if target char is already used by another char
                if(reverseMap.find(rep) == reverseMap.end()) {
                    charMap[og] = rep;      // Map original to replacement
                    reverseMap[rep] = og;   // Map replacement to original
                } else {
                    return false;
                }
            } else {
                // Original char already mapped, check if mapping is consistent
                char mapchar = charMap[og];
                if(mapchar != rep) return false;
            }
        }
        return true;
    }
};
