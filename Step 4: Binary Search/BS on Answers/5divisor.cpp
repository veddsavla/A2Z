#include <bits/stdc++.h>
using std::max;
using std::min;
using std::vector;

class Solution {
public:

    bool divisionSumCheck(vector<int>& nums, int threshold, int divisor){
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += ceil((double)(nums[i]) / (double)(divisor));
        }
        return sum<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int low = 1;
        int high = maxi;

        while (low <= high)
        {
             int mid = low + (high - low) / 2;

            if (divisionSumCheck(nums, threshold, mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};