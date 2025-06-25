#include <iostream>
#include <string>
using namespace std;

int convertToDecimal(string x){
    int length = x.length();
    int pow2=1;
    int result = 0;
    
    for(int i = length-1; i>=0; i--){
        if(x[i]=='1'){
            result += pow2;
        }
        pow2 *= 2;
    }
    return result;
}