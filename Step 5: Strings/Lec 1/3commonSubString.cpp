#include <vector>
#include <string>
using namespace std;
// This code finds the longest common prefix among a list of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Handle empty vector case
        if (strs.empty()) {
            return "";
        }
        
        // Start with the first string as the initial prefix
        string prefix = strs[0];
        
        // Compare with each subsequent string
        for (int i = 1; i < strs.size(); i++) {
            // Keep reducing the prefix until it matches the start of current string
            while (!prefix.empty() && strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
            }
            
            // If prefix becomes empty, no common prefix exists
            if (prefix.empty()) {
                break;
            }
        }
        
        return prefix;
    }
};