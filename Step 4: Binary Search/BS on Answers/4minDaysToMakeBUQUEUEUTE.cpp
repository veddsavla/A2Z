#include <bits/stdc++.h>
using std::max;
using std::min;
using std::vector;
// ÷hello
class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int daysReq)
    {
        int count = 0;
        int bouquets = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= daysReq)
            {
                count += 1;
            }
            else
            {
                bouquets += count / k;
                count = 0;
            }
        }
        bouquets += count / k;
        return bouquets >= m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        if((long long)m * k > n) return -1;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        while (low <= high)
        {
             int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid))
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