#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> solution;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n - 2; i++)
        {

            for (int j = i + 1; j < n - 1; j++)
            {

                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        solution.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(solution.begin(), solution.end());
        return ans;
    }
};