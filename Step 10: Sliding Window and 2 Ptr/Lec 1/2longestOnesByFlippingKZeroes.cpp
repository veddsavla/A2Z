class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int r = 0, l = 0, z = 0, maxLen = 0;
        int n = nums.size();

        while (r < n)
        {
            if (nums[r] == 0)
                z++;
            while (z > k)
            {
                if (nums[l] == 0)
                    z--;
                l++;
            }
            if (z <= k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};