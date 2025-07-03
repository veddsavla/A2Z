class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int ans = 0;
        int leftMax = 0, rightMax = 0; // Initialize both variables

        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (leftMax > height[l])
                {
                    ans += leftMax - height[l]; // Correct calculation
                }
                else
                {
                    leftMax = height[l];
                }
                l++; // Move left pointer
            }
            else
            {
                if (rightMax > height[r])
                {
                    ans += rightMax - height[r]; // Correct calculation
                }
                else
                {
                    rightMax = height[r];
                }
                r--; // Move right pointer
            }
        }
        return ans;
    }
};