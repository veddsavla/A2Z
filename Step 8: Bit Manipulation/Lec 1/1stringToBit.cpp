#include <iostream>
#include <string>
using namespace std;

string convert2Binary(int n)
{
    string ans = "";
    while (n != 1)
    {
        if (n % 2 == 1)
            ans += "1";
        else
            ans += "0";
        n = n / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}