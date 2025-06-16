# Binary Search Revision Guide

Binary search is a fundamental algorithm with O(log n) time complexity that works on sorted arrays by repeatedly dividing the search space in half. This guide summarizes key binary search problems and patterns from the codebase.

## 1. Basic Binary Search on 1D Arrays

### Search Insert Position
**Problem**: Find index where target is found, or where it would be inserted if not found.
```cpp
int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return low; // Important: return low for insertion position
}
```
**Key Insight**: When target isn't found, `low` will be at the insertion position.

### Find First and Last Position
**Problem**: Find first and last occurrence of target in sorted array.
```cpp
// First occurrence
int firstPosition(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int first = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid - 1;
            if (nums[mid] == target) first = mid;
        } else {
            low = mid + 1;
        }
    }
    return first;
}

// Last occurrence
int lastPosition(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int last = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
            low = mid + 1;
            if (nums[mid] == target) last = mid;
        } else {
            high = mid - 1;
        }
    }
    return last;
}
```
**Key Insight**: For first occurrence, move left even after finding target. For last occurrence, move right even after finding target.

### Search in Rotated Sorted Array
**Problem**: Search in a sorted array that has been rotated at an unknown pivot.
```cpp
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        
        // Check which half is sorted
        if (nums[low] <= nums[mid]) {
            // Left half is sorted
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1; // Target in sorted left half
            else
                low = mid + 1;  // Target in right half
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;  // Target in sorted right half
            else
                high = mid - 1; // Target in left half
        }
    }
    return -1;
}
```
**Key Insight**: Identify which half is sorted, then determine if target is in that sorted half.

### Find Peak Element
**Problem**: Find a peak element (greater than both neighbors) in an array.
```cpp
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid; // Peak is in left half including mid
        else
            low = mid + 1; // Peak is in right half
    }
    return low; // When low == high, we found the peak
}
```
**Key Insight**: Compare mid with mid+1 to determine which direction has a peak.

## 2. Binary Search on 2D Arrays

### Search in a Sorted Matrix
**Problem**: Search for target in a matrix where each row and column is sorted.
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n * m - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m, col = mid % m;
        
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
```
**Key Insight**: Treat the 2D matrix as a flattened sorted array using `row = mid / m` and `col = mid % m`.

### Row with Maximum Ones
**Problem**: Find the row with the maximum number of 1s in a binary matrix.
```cpp
int rowWithMax1s(vector<vector<int>>& mat) {
    int maxOnes = 0;
    int maxRowIndex = -1;
    
    for (int i = 0; i < mat.size(); i++) {
        int currentOnes = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) currentOnes++;
        }
        
        if (currentOnes > maxOnes) {
            maxOnes = currentOnes;
            maxRowIndex = i;
        }
    }
    
    return maxRowIndex;
}
```
**Optimization**: This can be optimized using binary search in each row to find the first 1.

## 3. Binary Search on Answer Space

### Koko Eating Bananas
**Problem**: Find minimum eating speed to consume all bananas within h hours.
```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long totalHours = 0;
        
        // Calculate hours needed at speed 'mid'
        for (int pile : piles) {
            totalHours += (pile + mid - 1) / mid; // Ceiling division
        }
        
        if (totalHours <= h)
            high = mid - 1; // Try to minimize speed
        else
            low = mid + 1;  // Need to increase speed
    }
    return low;
}
```
**Key Insight**: Binary search on the answer space (possible speeds) rather than the array itself.

### Median of Two Sorted Arrays
**Problem**: Find the median of two sorted arrays.
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, cnt = 0;
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;
    int id2 = n / 2;
    int id1 = id2 - 1;
    int id1E = -1, id2E = -1;

    // Merge arrays until reaching median positions
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
    
    // Handle remaining elements
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

    // Return median based on total length
    if (n % 2 == 0)
        return (id1E + id2E) / 2.0;
    else
        return id2E;
}
```
**Optimization**: This can be optimized to O(log(min(n1, n2))) using binary search.

## Binary Search Templates

### Standard Binary Search
```cpp
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Binary Search for Lower Bound
```cpp
int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) high = mid;
        else low = mid + 1;
    }
    return low;
}
```

### Binary Search for Upper Bound
```cpp
int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid;
        else low = mid + 1;
    }
    return low;
}
```

### Binary Search on Answer Space
```cpp
int binarySearchOnAnswer(vector<int>& nums, function<bool(int)> condition) {
    int low = /* minimum possible answer */;
    int high = /* maximum possible answer */;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (condition(mid)) {
            // Save answer and look for better one
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
```

## Common Binary Search Pitfalls

1. **Infinite loops**: Ensure mid calculation and pointer updates prevent infinite loops
2. **Integer overflow**: Use `mid = low + (high - low) / 2` instead of `mid = (low + high) / 2`
3. **Off-by-one errors**: Be careful with boundary conditions and <= vs <
4. **Handling duplicates**: Special care needed when array has duplicates
5. **Return value**: Return the correct pointer (low or high) based on problem requirements

## Practice Strategy

1. Master the basic binary search implementation
2. Practice variations: first/last occurrence, rotated arrays
3. Understand binary search on answer space
4. Apply to 2D arrays and complex problems
5. Review edge cases: empty arrays, single elements, duplicates 