#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int twoCount = 0, oneCount = 0, zeroCount = 0;

        // Count occurrences of 0, 1, and 2
        for (int num : nums)
        {
            if (num == 2)
                twoCount++;
            else if (num == 1)
                oneCount++;
            else
                zeroCount++;
        }

        // Overwrite nums array based on counts
        int i = 0;
        while (zeroCount--)
            nums[i++] = 0;
        while (oneCount--)
            nums[i++] = 1;
        while (twoCount--)
            nums[i++] = 2;
    }
};