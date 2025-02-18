#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr)
    {
        int N = arr.size();
        int ans = 0;

        // Iterate over the array
        for (int i = 1; i < N; i++)
            // Update ans with maximum sum of current and previous element
            ans = max(arr[i] + arr[i - 1], ans);

        // Return the maximum sum
        return ans;
    }
};