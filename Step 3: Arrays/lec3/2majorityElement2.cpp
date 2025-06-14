#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> freqMap;
        int n = nums.size();

        vector<int> ans;

        for (int num : nums)
        {
            freqMap[num]++;
        }

        for (auto it : freqMap)
        {
            if (it.second > n / 3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};