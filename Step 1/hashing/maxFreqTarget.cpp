#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 3, 3, 3, 5};
    int k = 4;
    
    int result = sol.maxFrequency(nums, k);
    cout << "Maximum frequency: " << result << endl;
    
    return 0;
}
