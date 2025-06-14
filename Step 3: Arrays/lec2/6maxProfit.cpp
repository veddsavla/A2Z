#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0; // Edge case: empty input

        int minPrice = prices[0]; // Track the lowest price seen so far
        int maxProfit = 0;        // Track maximum profit

        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]); // Update minimum price
        }

        return maxProfit;
    }
};