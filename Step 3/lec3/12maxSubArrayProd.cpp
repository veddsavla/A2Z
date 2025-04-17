#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int maxProd = INT_MIN;
        int prefixProd = 1;
        int suffixProd = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (prefixProd == 0)
                prefixProd = 1;
            if (suffixProd == 0)
                suffixProd = 1;

            prefixProd = prefixProd * nums[i];
            suffixProd = suffixProd * nums[n - i - 1];

            maxProd = max(maxProd, max(prefixProd, suffixProd));
        }
        return maxProd;
    }
};