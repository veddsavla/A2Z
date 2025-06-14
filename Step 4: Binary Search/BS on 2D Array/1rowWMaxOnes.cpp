#include <bits/stdc++.h>
using std::max;
using std::min;
using std::vector;

class Solution {
public:   
    int rowWithMax1s(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int maxRowIndex = -1;
        
        for(int i = 0; i < mat.size(); i++) {
            int currentOnes = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    currentOnes++;
                }
            }
            
            if(currentOnes > maxOnes) {
                maxOnes = currentOnes;
                maxRowIndex = i;
            }
        }
        
        return maxRowIndex;
    }
};