#include <bits/stdc++.h>
using std::vector;
using std::max;
using std::min;


class Solution
{
public:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int speed)
    {
        long long totalHours = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            // Use integer arithmetic to avoid overflow
            totalHours += (piles[i] + speed - 1) / speed;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = findMax(piles);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h)
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