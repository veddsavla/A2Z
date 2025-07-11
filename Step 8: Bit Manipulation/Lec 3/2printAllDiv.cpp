class Solution
{
public:
    vector<int> divisors(int n)
    {
        vector<int> ans;
        for (int i = 1; i * i < n; i++)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
                if (n / i != i)
                {
                    ans.push_back(n / i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};