#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}