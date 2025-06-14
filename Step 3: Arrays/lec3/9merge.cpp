#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = n + m - 1;
        int right = 0;

        while (left >= m && right < n)
        {

            swap(nums1[left], nums2[right]);
            left--, right++;
        }
        sort(nums1.begin(), nums1.end());
    }
};