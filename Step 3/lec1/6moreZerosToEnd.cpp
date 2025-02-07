#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int j = 0; // the number of zeroes replaced by number

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {                        // if the number is not a zero
                nums[j++] = nums[i]; // eliminating all zeroes and adding the numbers to the start
            }
        }

        // cout << j;

        while (j != nums.size())
        {
            nums[j] = 0;
            j++;
        }
        // return 0;
    }
};