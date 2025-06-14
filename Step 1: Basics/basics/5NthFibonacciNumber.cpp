#include <bits/stdc++.h>
using namespace std;

// int Fibonacci(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//         return 1;

//     int a = 0, b = 1, c;
//     for (int i = 2; i <= n; i++)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return b;
// }

int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}