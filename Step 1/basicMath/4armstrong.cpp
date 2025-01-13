#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n)
{
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

int main()
{
    int N, num;
    cin >> N;
    cout << "N: " << N << endl;

    num = N;
    int digits = countDigits(N);
    cout << "Number of Digits in N: " << digits << endl;

    int armSum = 0;
    for (int i = 0; i < digits; i++)
    {
        armSum += pow(N % 10, digits);
        N /= 10;
    }
    cout << "Armstrong Sum: " << armSum << endl;

    if (armSum == num)
        cout << "Armstrong Number" << endl;
    else
        cout << "Not an Armstrong Number" << endl;

    return 0;
}