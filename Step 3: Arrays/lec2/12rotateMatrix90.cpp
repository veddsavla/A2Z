#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // swap the elements - transpose
        // swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < matrix.size(); i++)
        {
            // MAKE A NOTE NOT TO START FROM J=0!!!!!!!!
            // OTHERWISE WILL TRANSPOSE TWICE!!!!!
            for (int j = i; j < matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};