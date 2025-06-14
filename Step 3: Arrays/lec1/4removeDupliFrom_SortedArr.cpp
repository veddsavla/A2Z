#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            { // if the num is equal to the number
              // before it
                // then the num's index shd be ++
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};