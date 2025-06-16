# DSA Pattern Templates

## Sliding Window Patterns

### Fixed Size Window
```cpp
// For a window of size k
vector<int> result;
int windowSum = 0;
    
// First window calculation
for (int i = 0; i < k; i++) {
    windowSum += nums[i];
}
result.push_back(windowSum);
    
// Slide window and update
for (int i = k; i < nums.size(); i++) {
    windowSum = windowSum - nums[i - k] + nums[i];
    result.push_back(windowSum);
}
```

### Variable Size Window (with condition)
```cpp
int left = 0, right = 0;
int result = 0; // or INT_MIN/INT_MAX based on problem
    
while (right < nums.size()) {
    // Add element at right to current window
    // Update window state
        
    // Shrink window from left if condition violated
    while (/* condition violated */) {
        // Remove element at left from window
        // Update window state
        left++;
    }
        
    // Update result based on current valid window
    result = max(result, right - left + 1); // for max length
        
    right++;
}
```

## Two Pointer Patterns

### Two Pointers (from both ends)
```cpp
int left = 0;
int right = nums.size() - 1;
    
while (left < right) {
    // Process elements at left and right
    // Move pointers based on condition
    if (/* condition */) {
        left++;
    } else {
        right--;
    }
}
```

### Fast and Slow Pointers
```cpp
ListNode* slow = head;
ListNode* fast = head;
    
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    
    // For cycle detection
    if (slow == fast) {
        return true; // Cycle detected
    }
}
```

## Tree Traversal Patterns

### DFS - Recursive
```cpp
void dfs(TreeNode* root) {
    if (!root) return;
    
    // Pre-order: Process root before children
    process(root);
    
    dfs(root->left);
    // In-order: Process root between children (for BST gives sorted order)
    // process(root);
    dfs(root->right);
    
    // Post-order: Process root after children
    // process(root);
}
```

### BFS - Level Order
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            currentLevel.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```

## Graph Patterns

### Graph DFS
```cpp
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    // Process node
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

### Graph BFS
```cpp
void bfs(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Process node
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### Dijkstra's Algorithm
```cpp
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (d > dist[node]) continue;
        
        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    return dist;
}
```

## Dynamic Programming Patterns

### 1D DP
```cpp
// Bottom-up approach
int solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    
    // Base case
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        // Recurrence relation
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
    }
    
    return *max_element(dp.begin(), dp.end());
}
```

### 2D DP
```cpp
// Bottom-up approach for problems like LCS
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### Memoization (Top-down)
```cpp
int helper(vector<int>& nums, int index, vector<int>& memo) {
    // Base case
    if (index >= nums.size()) return 0;
    
    // Check if already computed
    if (memo[index] != -1) return memo[index];
    
    // Recurrence relation with memoization
    memo[index] = max(nums[index] + helper(nums, index + 2, memo), 
                       helper(nums, index + 1, memo));
    
    return memo[index];
}

int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return helper(nums, 0, memo);
}
```

## Backtracking Pattern
```cpp
void backtrack(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
    // Base case: if current combination is complete
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        // Skip used elements
        if (used[i]) continue;
        
        // Skip duplicates (for problems with duplicates)
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        
        // Make choice
        used[i] = true;
        current.push_back(nums[i]);
        
        // Explore
        backtrack(nums, current, result, used);
        
        // Undo choice (backtrack)
        current.pop_back();
        used[i] = false;
    }
}
```

## Binary Search Pattern
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Target not found
}
```

## Union Find (Disjoint Set)
```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

## Trie Pattern
```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
    
private:
    TrieNode* searchPrefix(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return nullptr;
            }
            current = current->children[index];
        }
        return current;
    }
};
``` 