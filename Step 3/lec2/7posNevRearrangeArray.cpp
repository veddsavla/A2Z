#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans(nums.size(), 0);

        int pid = 0;
        int nid = 1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0){
                ans[nid]=nums[i];
                nid+=2;
            } else {
                ans[pid]=nums[i];
                pid+=2;
            }
        }

        return ans;
    }
};