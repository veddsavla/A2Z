#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<int, int> hash;

        for (auto num : nums)
        {
            hash[num]++;
        }

        for (auto [key, value] : hash)
        {
            if (value == 1)
            {
                return key;
            }
        }
        return 0;
    }
};