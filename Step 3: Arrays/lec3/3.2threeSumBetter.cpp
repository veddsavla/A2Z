#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> st;
            for(int i = 0; i < nums.size(); i++){
                    set<int> hashset;
                for(int j = i+1; j < nums.size(); j++){
                    int third = -(nums[i] + nums[j]);
                    if(hashset.find(third) != hashset.end()) { // if it exists in the set
                        vector<int> temp = {nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    
                    hashset.insert(nums[j]);
    
                }
            }
            vector<vector<int>> answer(st.begin(), st.end());
            return answer;
        }
    };