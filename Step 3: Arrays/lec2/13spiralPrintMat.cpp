#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;

        int rows = matrix.size();
        int column = matrix[0].size();

        int top = 0;
        int right = column - 1;
        int left = 0;
        int bottom = rows - 1;

        // move : left to right -> top to bottom -> right to left -> bottom to
        // top

        while (top <= bottom && left <= right)
        {
            // move left to right :
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }

            top++;

            // top to bottom :
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }

            right--;

            if (top <= bottom)
            {
                // right to left :
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                // bottom to top :
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};