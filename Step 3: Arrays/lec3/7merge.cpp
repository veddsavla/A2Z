#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> answer;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        for (int i = 0; i < n; i++)
        {
            if (answer.empty() || intervals[i][0] > answer.back()[1])
            {
                answer.push_back(intervals[i]);
            }
            else
            {
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            }
        }

        return answer;
    }
};