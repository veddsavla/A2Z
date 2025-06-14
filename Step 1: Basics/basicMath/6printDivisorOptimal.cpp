#include <iostream>
#include <math.h>
using namespace std;

void divisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << ", ";
            if (n / i != i)
            {
                cout << n / i << ", ";
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    cout << "divisors of N: ";
    divisors(N);
    cout << endl;
    return 0;
}
