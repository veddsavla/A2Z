#include <bits/stdc++.h>
using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int i = 0, j = 0, cnt = 1;
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        int ele = -1;

        while (i < n1 && j < n2)
        {
            int val;
            if (a[i] < b[j])
            {
                val = a[i++];
            }
            else
            {
                val = b[j++];
            }
            if (cnt == k)
                ele = val;
            cnt++;
        }
        while (i < n1)
        {
            if (cnt == k)
                ele = a[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == k)
                ele = b[j];
            cnt++;
            j++;
        }

        return ele;
    }
};
