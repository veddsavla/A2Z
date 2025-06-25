#include <iostream>
using namespace std;

// to remove the last set bit in a number n
int removeLastSetBit(int n)
{
    if (n == 0)
        return 0;
    return n & (n - 1);
}