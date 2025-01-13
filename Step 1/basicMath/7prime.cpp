#include <iostream>
using namespace std;

bool isPrime(int n) {
  int count = 0;

  if (n == 1) {
    return false;
  }

  for (int i = 2; i <= n; i++) {

    if (n % i == 0 && i != n) {
      count++;
    }
  }
  if (count == 0) {

    return true;
  } else {
    return false;
  }
}

int main() {
  int n;
  cin >> n;
  cout << isPrime(n);
}
