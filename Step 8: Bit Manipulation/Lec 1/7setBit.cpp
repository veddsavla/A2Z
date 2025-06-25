#include <iostream>
using namespace std;

int setBit(int n, int i)
{
    int mask = (1 << i); 
    return n OR mask; 
}