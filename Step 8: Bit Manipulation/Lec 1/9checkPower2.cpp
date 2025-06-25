#include <iostream>
using namespace std;
// to check if a number is a power of 2
bool checkPower2(int n){
    if(n<=0) return false;
    return (n & (n-1)==0);
}