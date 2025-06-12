#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Helper function to check if it's possible to ship within 'days' using 'capacity'
    bool isMin(vector<int>& weights, int days, int capacity) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > capacity) {
                sum = weights[i];
                count += 1;
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        int low = maxi;
        int high = sum;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isMin(weights, days, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
