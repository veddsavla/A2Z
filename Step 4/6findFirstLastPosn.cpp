#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int firstPosn(vector<int>& nums, int target){
            int n = nums.size();
            int low = 0;
            int high = n-1;
            int first = -1;
    
            while(high>=low){
                int mid = (low + high)/2;
                if(nums[mid]>=target) high = mid - 1;
                else low = mid + 1;
                if(nums[mid]==target) first = mid;
            }
            
    
            return first;
        }
        int lastPosn(vector<int>& nums, int target){
            int n = nums.size();
            int low = 0;
            int high = n-1;
            int last = -1;
    
            while(high>=low){
                int mid = (low + high)/2;
                if(nums[mid]<=target) low = mid + 1;
                else high = mid - 1;
                if(nums[mid]==target) last = mid;
            }
            return last;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            return {firstPosn(nums, target), lastPosn(nums, target)};
        }
    };