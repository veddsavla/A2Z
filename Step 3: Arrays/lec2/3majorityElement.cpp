#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> freqMap;
        int n = nums.size();

        // Count occurrences
        for (int num : nums)
        {
            freqMap[num]++;
        }

        // Find the majority element
        for (auto it : freqMap)
        {
            if (it.second > n / 2)
            {
                return it.first; // Directly return the majority element
            }
        }

        return -1;
    }
};