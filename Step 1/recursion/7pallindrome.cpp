#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered = "";

        for (auto ch : s)
        {
            if (isalnum(ch))
            {
                filtered += tolower(ch);
            }
        }

        int left = 0, right = filtered.size() - 1;
        while (left < right)
        {
            if (filtered[left] != filtered[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};