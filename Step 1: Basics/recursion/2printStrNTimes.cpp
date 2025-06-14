#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printGfg(int n)
    {

        if (n <= 0)
        {
            return;
        }

        printGfg(n - 1);
        cout << "GFG ";
    }
};
