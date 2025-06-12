#include <bits/stdc++.h>
using std::max;
using std::min;
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, cnt = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int id2 = n / 2;
        int id1 = id2 - 1;
        int id1E = -1, id2E = -1;

        while (i < n1 && j < n2) {
            int val;
            if (nums1[i] < nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            if (cnt == id1) id1E = val;
            if (cnt == id2) id2E = val;
            cnt++;
        }
        while (i < n1) {
            if (cnt == id1) id1E = nums1[i];
            if (cnt == id2) id2E = nums1[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == id1) id1E = nums2[j];
            if (cnt == id2) id2E = nums2[j];
            cnt++;
            j++;
        }

        if (n % 2 == 0)
            return (id1E + id2E) / 2.0;
        else
            return id2E;
    }
};
