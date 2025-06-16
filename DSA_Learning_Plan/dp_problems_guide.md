# Dynamic Programming Problems by Pattern

## 1. Fibonacci Sequence Pattern
Problems where each state depends on the sum of previous states.

### Problems:
1. **Fibonacci Number** (Easy)
   - State: `dp[i] = dp[i-1] + dp[i-2]`
   - Base: `dp[0] = 0, dp[1] = 1`

2. **Climbing Stairs** (Easy)
   - State: `dp[i] = dp[i-1] + dp[i-2]`
   - Base: `dp[1] = 1, dp[2] = 2`

3. **House Robber** (Medium)
   - State: `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`
   - Base: `dp[0] = nums[0], dp[1] = max(nums[0], nums[1])`

4. **Jump Game** (Medium)
   - State: `dp[i] = max(dp[i], dp[j] + 1)` where `j < i` and `j + nums[j] >= i`
   - Base: `dp[0] = 0`

## 2. Longest Increasing Subsequence (LIS) Pattern
Problems involving finding subsequences with specific properties.

### Problems:
1. **Longest Increasing Subsequence** (Medium)
   - State: `dp[i] = max(dp[j] + 1)` where `j < i` and `nums[j] < nums[i]`
   - Base: `dp[i] = 1` for all i

2. **Maximum Length of Pair Chain** (Medium)
   - State: `dp[i] = max(dp[j] + 1)` where `j < i` and `pairs[j][1] < pairs[i][0]`
   - Base: `dp[i] = 1` for all i

3. **Russian Doll Envelopes** (Hard)
   - State: `dp[i] = max(dp[j] + 1)` where `j < i`, `envelopes[j][0] < envelopes[i][0]`, and `envelopes[j][1] < envelopes[i][1]`
   - Base: `dp[i] = 1` for all i

## 3. Knapsack Pattern
Problems involving selection of items with constraints.

### Problems:
1. **0/1 Knapsack** (Medium)
   - State: `dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])`
   - Base: `dp[0][w] = 0, dp[i][0] = 0`

2. **Partition Equal Subset Sum** (Medium)
   - State: `dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]`
   - Base: `dp[0][0] = true, dp[i][0] = true, dp[0][j] = false for j > 0`

3. **Target Sum** (Medium)
   - State: `dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]`
   - Base: `dp[0][0] = 1` (modified for offset)

4. **Coin Change** (Medium)
   - State: `dp[i] = min(dp[i], dp[i-coin] + 1)`
   - Base: `dp[0] = 0, dp[i] = infinity for i > 0`

## 4. Matrix Path Problems
Problems involving finding optimal paths through a grid.

### Problems:
1. **Minimum Path Sum** (Medium)
   - State: `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`
   - Base: `dp[0][0] = grid[0][0]`

2. **Unique Paths** (Medium)
   - State: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
   - Base: `dp[0][j] = 1, dp[i][0] = 1`

3. **Dungeon Game** (Hard)
   - State: `dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])`
   - Base: Calculate from bottom-right to top-left

4. **Cherry Pickup** (Hard)
   - State: `dp[r1][c1][c2] = grid[r1][c1] + (c1 != c2 ? grid[r2][c2] : 0) + max(dp[r1+1][c1][c2], dp[r1+1][c1][c2+1], dp[r1+1][c1+1][c2], dp[r1+1][c1+1][c2+1])`
   - Base: Bottom-up approach

## 5. String Manipulation Pattern
Problems involving operations on strings.

### Problems:
1. **Longest Common Subsequence** (Medium)
   - State: `dp[i][j] = dp[i-1][j-1] + 1` if `s1[i-1] == s2[j-1]` else `max(dp[i-1][j], dp[i][j-1])`
   - Base: `dp[0][j] = 0, dp[i][0] = 0`

2. **Edit Distance** (Hard)
   - State: `dp[i][j] = dp[i-1][j-1]` if `word1[i-1] == word2[j-1]` else `1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`
   - Base: `dp[i][0] = i, dp[0][j] = j`

3. **Distinct Subsequences** (Hard)
   - State: `dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0)`
   - Base: `dp[i][0] = 1, dp[0][j] = 0 for j > 0`

4. **Palindromic Substrings** (Medium)
   - State: `dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i+1][j-1])`
   - Base: `dp[i][i] = true`

## 6. Decision Making Pattern
Problems involving making decisions at each step.

### Problems:
1. **Best Time to Buy and Sell Stock** (Easy)
   - State: Track minimum price and maximum profit
   - No traditional DP table

2. **Best Time to Buy and Sell Stock with Cooldown** (Medium)
   - State: `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])` (not holding)
   - State: `dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])` (holding)
   - Base: `dp[0][0] = 0, dp[0][1] = -prices[0], dp[1][0] = max(0, prices[1] - prices[0]), dp[1][1] = max(-prices[0], -prices[1])`

3. **Best Time to Buy and Sell Stock with Transaction Fee** (Medium)
   - State: `dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)` (not holding)
   - State: `dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])` (holding)
   - Base: `dp[0][0] = 0, dp[0][1] = -prices[0]`

## 7. Game Theory Pattern
Problems involving optimal play against an opponent.

### Problems:
1. **Stone Game** (Medium)
   - State: `dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])`
   - Base: `dp[i][i] = piles[i]`

2. **Predict the Winner** (Medium)
   - State: `dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])`
   - Base: `dp[i][i] = nums[i]`

3. **Can I Win** (Medium)
   - State: Use memoization with bit manipulation
   - Base: Check if first player can force a win

## 8. Interval DP Pattern
Problems involving merging intervals optimally.

### Problems:
1. **Burst Balloons** (Hard)
   - State: `dp[i][j] = max(dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1])` for all `k` in range `[i,j]`
   - Base: Build from smaller intervals to larger ones

2. **Minimum Cost to Merge Stones** (Hard)
   - State: `dp[i][j][k] = min(dp[i][mid][1] + dp[mid+1][j][k-1])` for all valid `mid`
   - Base: Complex, involves multi-level state transitions

## 9. Counting DP Pattern
Problems involving counting the number of ways to achieve a goal.

### Problems:
1. **Climbing Stairs** (Easy)
   - State: `dp[i] = dp[i-1] + dp[i-2]`
   - Base: `dp[1] = 1, dp[2] = 2`

2. **Unique Paths** (Medium)
   - State: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
   - Base: `dp[0][j] = 1, dp[i][0] = 1`

3. **Coin Change 2** (Medium)
   - State: `dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]`
   - Base: `dp[i][0] = 1`

4. **Number of Dice Rolls With Target Sum** (Medium)
   - State: `dp[d][target] = sum(dp[d-1][target-face])` for all valid faces
   - Base: `dp[0][0] = 1`

## 10. Bitmask DP Pattern
Problems involving using bits to represent states.

### Problems:
1. **Traveling Salesman Problem** (Hard)
   - State: `dp[mask][i] = min(dp[mask|(1<<j)][j] + cost[i][j])` for all unvisited cities j
   - Base: `dp[1<<i][i] = 0` for starting city i

2. **Minimum Cost to Visit Every Node** (Hard)
   - State: `dp[mask][i] = min(dp[mask^(1<<i)][j] + cost[j][i])` for all j in mask
   - Base: `dp[1][0] = 0`

## Study Approach for Each Pattern:

1. **Understand the pattern** - Learn how states are defined and transitions work
2. **Start with easy problems** - Build confidence with simpler examples
3. **Visualize state transitions** - Draw tables or trees to see how values propagate
4. **Implement both approaches** - Practice both top-down (memoization) and bottom-up (tabulation)
5. **Optimize space** - Learn to reduce memory usage by only keeping necessary states
6. **Solve variations** - Apply the pattern to different constraints and problem settings 