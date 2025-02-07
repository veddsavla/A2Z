#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int num : nums)
        {
            result ^= num; // XOR cancels out duplicate numbers
        }
        return result;
    }
};

// for the input [4, 1, 2, 1, 2] :-

// result = 0
// result ^= 4  →  result = 4
// result ^= 1  →  result = 4 ^ 1
// result ^= 2  →  result = (4 ^ 1) ^ 2
// result ^= 1  →  result = ((4 ^ 1) ^ 2) ^ 1  →  4 ^ (1 ^ 1) ^ 2  →  4 ^ 0 ^ 2  →  4 ^ 2
// result ^= 2  →  4 ^ 2 ^ 2  →  4 ^ 0  →  4

