#include <iostream>
using namespace std;

// to clear the ith bit in a number n
int clearBit(int n, int i)
{
    int mask = ~(1 << i); // create a mask with 0 at the ith bit
    return n & mask; // use bitwise AND to clear the ith bit
}