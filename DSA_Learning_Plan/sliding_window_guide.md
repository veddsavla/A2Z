# Sliding Window & Two Pointer Techniques

## Sliding Window Technique

The sliding window pattern is used to perform operations on a specific window size of an array or string. The window can be fixed or variable in size.

### When to Use Sliding Window
- Finding subarrays/substrings that satisfy certain conditions
- Computing running averages or sums
- Finding longest/shortest subarray with a specific property
- Problems involving consecutive elements

### Fixed Size Window Pattern

In this pattern, the window size remains constant throughout the algorithm.

#### Template:
```cpp
vector<int> fixedSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();
    
    // Handle edge cases
    if (n == 0 || k == 0 || k > n) return result;
    
    // Calculate first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    result.push_back(windowSum);
    
    // Slide window and update result
    for (int i = k; i < n; i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        result.push_back(windowSum);
    }
    
    return result;
}
```

#### Example Problems:
1. **Maximum Sum Subarray of Size K**
2. **Find All Anagrams in a String**
3. **Permutation in String**
4. **Repeated DNA Sequences**

### Variable Size Window Pattern

In this pattern, the window size changes dynamically based on certain conditions.

#### Template:
```cpp
int variableSlidingWindow(vector<int>& nums, int target) {
    int result = 0;  // Initialize based on problem (e.g., 0, INT_MAX, or -1)
    int left = 0;
    int sum = 0;  // Or other metric based on problem
    
    for (int right = 0; right < nums.size(); right++) {
        // Expand window by including right element
        sum += nums[right];
        
        // Contract window from left while condition is violated
        while (sum > target) {  // Adjust condition based on problem
            sum -= nums[left];
            left++;
        }
        
        // Update result if needed
        result = max(result, right - left + 1);  // For max length
    }
    
    return result;
}
```

#### Example Problems:
1. **Minimum Size Subarray Sum**
2. **Longest Substring Without Repeating Characters**
3. **Minimum Window Substring**
4. **Longest Substring with At Most K Distinct Characters**
5. **Fruit Into Baskets**

### Advanced Sliding Window Techniques

#### Using Hash Maps/Sets for Window State
```cpp
int slidingWindowWithMap(string s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        
        // Adjust window based on map state
        while (charCount.size() > k) {
            if (--charCount[s[left]] == 0) {
                charCount.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

#### Sliding Window with Multiple Conditions
```cpp
int slidingWindowMultiCondition(string s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    int distinctChars = 0, maxFreq = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        maxFreq = max(maxFreq, charCount[s[right]]);
        
        // Window is valid when: (right-left+1) - maxFreq <= k
        // This means we can change at most k characters to make all chars the same
        while ((right - left + 1) - maxFreq > k) {
            charCount[s[left]]--;
            left++;
            
            // Update maxFreq if needed (can be optimized)
            maxFreq = 0;
            for (auto& pair : charCount) {
                maxFreq = max(maxFreq, pair.second);
            }
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

## Two Pointer Technique

The two pointer technique uses two pointers to solve problems in a single pass through the data.

### When to Use Two Pointers
- Searching pairs in a sorted array
- Removing duplicates
- Fast and slow pointers for linked lists
- Merging two sorted arrays
- Finding triplets or quadruplets with specific properties

### Two Pointers from Both Ends

#### Template:
```cpp
vector<int> twoPointerFromEnds(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {-1, -1}; // No solution found
}
```

#### Example Problems:
1. **Two Sum (sorted array)**
2. **Container With Most Water**
3. **Trapping Rain Water**
4. **3Sum, 4Sum**
5. **Valid Palindrome**

### Fast and Slow Pointers

#### Template:
```cpp
bool hasCycle(ListNode* head) {
    if (!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    
    return false; // No cycle
}
```

#### Example Problems:
1. **Linked List Cycle**
2. **Find the Middle of Linked List**
3. **Palindrome Linked List**
4. **Cycle Detection and Finding Cycle Start**
5. **Happy Number**

### Multiple Pointers

#### Template:
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    
    // Sort for two-pointer technique
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                
                left++;
                right--;
            }
        }
    }
    
    return result;
}
```

#### Example Problems:
1. **3Sum**
2. **3Sum Closest**
3. **4Sum**
4. **Sort Colors (Dutch National Flag problem)**

## Common Patterns & Techniques

### 1. Expanding and Contracting Windows
- Start with an empty window
- Expand by adding elements to the right
- Contract from the left when a condition is violated
- Update result with each valid window

### 2. Maintaining Window State
- Use variables to track window properties (sum, product, max/min)
- Use hash maps/sets for frequency counting or uniqueness checking
- Update state efficiently when sliding the window

### 3. Handling Edge Cases
- Empty arrays or strings
- Window size greater than array length
- Negative numbers (for sum-based problems)
- Duplicates in the array

### 4. Optimization Techniques
- Avoid recalculating window properties
- Use efficient data structures (e.g., deque for sliding window maximum)
- Early termination when possible

## Problem-Solving Framework

1. **Identify the pattern**:
   - Is it a subarray/substring problem?
   - Are we looking for consecutive elements?
   - Is the array sorted (for two pointers)?

2. **Choose the appropriate technique**:
   - Fixed vs. variable sliding window
   - Two pointers from both ends
   - Fast and slow pointers

3. **Define window state**:
   - What information needs to be tracked?
   - How to update efficiently when sliding?

4. **Implement the solution**:
   - Initialize pointers and state variables
   - Process elements and update window
   - Track result based on problem requirements

5. **Test with examples**:
   - Small test cases
   - Edge cases
   - Verify time and space complexity

## Practice Problems by Difficulty

### Easy:
1. Maximum Sum Subarray of Size K
2. Find All Anagrams in a String
3. Two Sum (sorted array)
4. Remove Duplicates from Sorted Array
5. Linked List Cycle

### Medium:
1. Longest Substring Without Repeating Characters
2. Minimum Size Subarray Sum
3. Permutation in String
4. 3Sum
5. Container With Most Water
6. Longest Repeating Character Replacement

### Hard:
1. Minimum Window Substring
2. Sliding Window Maximum
3. Longest Substring with At Most K Distinct Characters
4. Trapping Rain Water
5. Substring with Concatenation of All Words 