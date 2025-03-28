#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        // hi 
        
        if (index == -1)
        {
            return reverse(nums.begin(), nums.end());
        }

        for (int i = n - 1; i >= index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        return reverse(nums.begin() + index + 1, nums.end());
    }
};