class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int total = 1 << n; // 2^n subsets
        vector<vector<int>> ans;

        for (int i = 0; i < total; i++)
        {
            vector<int> subset;
            for (int j = 0; j < n; j++)
            {
                // Check if j-th bit in i is set
                if (i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};
