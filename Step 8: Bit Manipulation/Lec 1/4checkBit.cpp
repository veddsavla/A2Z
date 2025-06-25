// to check if the ith bit is set in a number n
#include <iostream>
using namespace std;

// using left shift
bool checkBitLeftShift(int n, int i)
{
    int mask = 1 << i;
    return (n & mask) != 0;
}

// using right shift
bool checkBitRightShift(int n, int i)
{
    return (n >> i) & 1;
}