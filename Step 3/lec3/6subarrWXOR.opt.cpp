#include <bits/stdc++.h>
using namespace std;

int Solutionsolve(vector<int> &A, int B)
{

    map<int, int> mpp;
    int n = A.size();
    int sub = 0;
    int xr = 0;

    mpp[xr]++;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ A[i];
        int x = xr ^ B;

        sub += mpp[x];
        mpp[xr]++;
    }
    return sub;
}
