//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int sumOfDivisors(int n) {
        int totalSum = 0;
    
        for(int num = 1; num <= n; num++) {
        
            for(int i = 1; i <= num; i++) {
                if(num % i == 0) {
                    totalSum += i;
                }
            }
        }
        
        return totalSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends