#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        int rep = 0;
        int missing = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                rep = arr[i - 1];
            }
        }

        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = 1; i <= arr.size(); i++)
        {
            if (s.find(i) == s.end())
            {
                missing = i;
                break;
            }
        }
        return {rep, missing};
    }
};
