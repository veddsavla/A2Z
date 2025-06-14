#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal;

        for (int row = 0; row < numRows; row++)
        {

            vector<int> ansRow;
            long long ans = 1;
            ansRow.push_back(ans);

            for (int col = 1; col <= row; col++)
            {
                ans = ans * (row - col + 1) / col;
                ansRow.push_back(ans);
            }
            pascal.push_back(ansRow);
        }
        return pascal;
    }
};