vector<int> primeNums(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // ans.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
                ans.push_back(i);
            }
        }
    }
    if (n != 1)
        ans.push_back(n);
    return ans;
}

class Solution
{
public:
    vector<vector<int>> primeFactors(vector<int> &queries)
    {
        vector<vector<int>> result;
        for (int i = 0; i < queries.size(); i++)
        {
            result.push_back(primeNums(queries[i]));
        }
        return result;
    }
};