#include <iostream>
using namespace std;
// to toggle the ith bit in a number n
int toggleBit(int n, int i)
{
    int mask = 1 << i;
    return n^ mask;
}
