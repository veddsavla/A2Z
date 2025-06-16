# Graph Algorithms Guide

## Graph Representations

### Adjacency Matrix
```cpp
// For a graph with n vertices
vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

// Add edge from u to v with weight w
adjMatrix[u][v] = w;

// For undirected graph, add both directions
adjMatrix[u][v] = adjMatrix[v][u] = w;
```

**Pros:**
- Simple for dense graphs
- O(1) time to check if edge exists
- Easy to implement

**Cons:**
- O(V²) space complexity
- Inefficient for sparse graphs
- Slow to iterate over all edges

### Adjacency List
```cpp
// For a graph with n vertices
vector<vector<pair<int, int>>> adjList(n);

// Add edge from u to v with weight w
adjList[u].push_back({v, w});

// For undirected graph, add both directions
adjList[u].push_back({v, w});
adjList[v].push_back({u, w});
```

**Pros:**
- Space efficient for sparse graphs: O(V + E)
- Faster to iterate over all edges
- Better for most graph algorithms

**Cons:**
- O(degree) time to check if edge exists
- More complex implementation

## Graph Traversal Algorithms

### Depth-First Search (DFS)
```cpp
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    // Process current node
    visited[node] = true;
    cout << node << " ";
    
    // Visit all neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

// Driver function
void dfsTraversal(vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    dfs(start, adjList, visited);
}
```

**Applications:**
- Cycle detection
- Topological sorting
- Connected components
- Maze solving
- Path finding

### Breadth-First Search (BFS)
```cpp
void bfs(vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    // Start BFS from the given node
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Process current node
        cout << node << " ";
        
        // Visit all neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

**Applications:**
- Shortest path in unweighted graph
- Connected components
- Level-order traversal
- Finding all nodes at distance k
- Network flow algorithms

## Shortest Path Algorithms

### Dijkstra's Algorithm
For finding the shortest path from a source node to all other nodes in a weighted graph with non-negative weights.

```cpp
vector<int> dijkstra(vector<vector<pair<int, int>>>& adjList, int start) {
    int n = adjList.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        // Skip if we've found a better path already
        if (distance > dist[node]) continue;
        
        // Check all neighbors
        for (auto& edge : adjList[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            
            // Relaxation step
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    
    return dist;
}
```

**Time Complexity:** O((V + E) log V) with priority queue
**Applications:**
- GPS navigation
- Network routing protocols
- Flight scheduling
- Resource allocation

### Bellman-Ford Algorithm
For finding the shortest path from a source node to all other nodes, can handle negative weights and detect negative cycles.

```cpp
vector<int> bellmanFord(vector<vector<int>>& edges, int n, int start) {
    // Initialize distances
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    // Relax all edges V-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return {}; // Empty vector indicates negative cycle
        }
    }
    
    return dist;
}
```

**Time Complexity:** O(V * E)
**Applications:**
- Networks with negative weights
- Arbitrage detection in currency exchange
- Traffic routing with constraints

### Floyd-Warshall Algorithm
For finding the shortest paths between all pairs of nodes.

```cpp
vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph; // Copy the original graph
    
    // Initialize distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INT_MAX; // No direct edge
            }
        }
    }
    
    // Consider each vertex as an intermediate
    for (int k = 0; k < n; k++) {
        // Consider all pairs of vertices (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Skip if there's no path from i to k or k to j
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                
                // Update if path through k is shorter
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}
```

**Time Complexity:** O(V³)
**Applications:**
- All-pairs shortest paths
- Transitive closure of a graph
- Detecting negative cycles
- Finding the diameter of a graph

## Minimum Spanning Tree Algorithms

### Kruskal's Algorithm
Builds MST by adding edges in increasing weight order, avoiding cycles.

```cpp
// Edge structure
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find data structure
class UnionFind {
private:
    vector<int> parent, rank;
    
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
};

vector<Edge> kruskal(vector<Edge>& edges, int n) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    vector<Edge> mst;
    
    for (Edge& edge : edges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);
        
        // Add edge if it doesn't create a cycle
        if (rootU != rootV) {
            mst.push_back(edge);
            uf.unionSets(rootU, rootV);
        }
        
        // Stop when MST is complete
        if (mst.size() == n - 1) break;
    }
    
    return mst;
}
```

**Time Complexity:** O(E log E) due to sorting
**Applications:**
- Network design
- Cluster analysis
- Image segmentation

### Prim's Algorithm
Builds MST by growing a tree from a starting vertex.

```cpp
vector<pair<int, int>> prim(vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size();
    vector<int> key(n, INT_MAX); // Key values to pick minimum edge
    vector<bool> inMST(n, false); // Track vertices in MST
    vector<int> parent(n, -1); // Store MST
    
    // Start with vertex 0
    key[0] = 0;
    
    // Priority queue: {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue; // Skip if already in MST
        
        inMST[u] = true;
        
        // Check all adjacent vertices
        for (auto& edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // Update key if vertex not in MST and weight is smaller
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    
    // Construct MST from parent array
    vector<pair<int, int>> mst;
    for (int i = 1; i < n; i++) {
        mst.push_back({parent[i], i});
    }
    
    return mst;
}
```

**Time Complexity:** O((V + E) log V) with priority queue
**Applications:**
- Network design
- Approximation algorithms
- Clustering

## Advanced Graph Algorithms

### Topological Sort
Orders vertices such that for every directed edge (u, v), u comes before v.

```cpp
vector<int> topologicalSort(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> inDegree(n, 0);
    
    // Calculate in-degree of each vertex
    for (int u = 0; u < n; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }
    
    // Queue for vertices with no incoming edges
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        // Reduce in-degree of adjacent vertices
        for (int v : adjList[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Check if graph has a cycle
    if (result.size() != n) {
        cout << "Graph has a cycle, topological sort not possible" << endl;
        return {};
    }
    
    return result;
}
```

**Time Complexity:** O(V + E)
**Applications:**
- Task scheduling
- Build systems
- Course prerequisites
- Package dependencies

### Strongly Connected Components (Kosaraju's Algorithm)
Finds groups of vertices where each vertex is reachable from every other vertex in the group.

```cpp
void fillOrder(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& stack) {
    visited[node] = true;
    
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            fillOrder(neighbor, adjList, visited, stack);
        }
    }
    
    // Push vertex to stack when all descendants are processed
    stack.push(node);
}

void dfsUtil(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adjList, visited, component);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(vector<vector<int>>& adjList) {
    int n = adjList.size();
    stack<int> stack;
    vector<bool> visited(n, false);
    
    // Step 1: Fill vertices in stack according to their finish times
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            fillOrder(i, adjList, visited, stack);
        }
    }
    
    // Step 2: Create transpose of the graph
    vector<vector<int>> transpose(n);
    for (int u = 0; u < n; u++) {
        for (int v : adjList[u]) {
            transpose[v].push_back(u);
        }
    }
    
    // Step 3: Process vertices in order defined by stack
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> scc;
    
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        
        if (!visited[node]) {
            vector<int> component;
            dfsUtil(node, transpose, visited, component);
            scc.push_back(component);
        }
    }
    
    return scc;
}
```

**Time Complexity:** O(V + E)
**Applications:**
- Finding cycles in directed graphs
- Social network analysis
- Web page ranking algorithms

### Articulation Points and Bridges
Identifies critical nodes and edges in a graph.

```cpp
void findArticulationPoints(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> disc(n, -1); // Discovery time
    vector<int> low(n, -1);  // Earliest visited vertex
    vector<bool> isArticulation(n, false);
    vector<bool> visited(n, false);
    int time = 0;
    
    function<void(int, int)> dfs = [&](int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;
        
        for (int v : adjList[u]) {
            if (v == parent) continue; // Skip parent
            
            if (!visited[v]) {
                children++;
                dfs(v, u);
                
                // Check if subtree rooted at v has connection to ancestors of u
                low[u] = min(low[u], low[v]);
                
                // Case 1: u is root and has multiple children
                if (parent == -1 && children > 1) {
                    isArticulation[u] = true;
                }
                
                // Case 2: u is not root and low value of one of its children is >= disc value of u
                if (parent != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else {
                // Update low value of u for parent function calls
                low[u] = min(low[u], disc[v]);
            }
        }
    };
    
    // Call DFS for each unvisited vertex
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    // Print articulation points
    cout << "Articulation Points: ";
    for (int i = 0; i < n; i++) {
        if (isArticulation[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
```

**Time Complexity:** O(V + E)
**Applications:**
- Network reliability analysis
- Critical infrastructure identification
- Vulnerability assessment

## Graph Problem-Solving Strategies

### 1. Identify the Graph Structure
- Directed vs. Undirected
- Weighted vs. Unweighted
- Cyclic vs. Acyclic
- Dense vs. Sparse

### 2. Choose the Right Representation
- Adjacency Matrix for dense graphs
- Adjacency List for sparse graphs
- Edge List for algorithms like Kruskal's

### 3. Select the Appropriate Algorithm
- Shortest Path: Dijkstra's, Bellman-Ford, or Floyd-Warshall
- Connectivity: DFS or BFS
- Minimum Spanning Tree: Kruskal's or Prim's
- Directed Acyclic Graph (DAG): Topological Sort

### 4. Optimize for Specific Constraints
- Memory constraints: Consider space-efficient representations
- Time constraints: Choose algorithms with appropriate complexity
- Negative weights: Use Bellman-Ford instead of Dijkstra's
- All-pairs problems: Use Floyd-Warshall

### 5. Common Graph Problem Patterns
- Path finding: BFS (unweighted) or Dijkstra's (weighted)
- Connectivity: DFS or Union-Find
- Cycle detection: DFS with visited tracking
- Bipartite checking: BFS with coloring
- Topological ordering: Kahn's algorithm or DFS

## Practice Problems by Difficulty

### Easy:
1. Find if Path Exists in Graph
2. Number of Islands
3. Flood Fill
4. Find the Town Judge
5. Find Center of Star Graph

### Medium:
1. Course Schedule (Topological Sort)
2. Network Delay Time (Dijkstra's)
3. Redundant Connection (Union-Find)
4. Evaluate Division (Graph Traversal)
5. Clone Graph
6. Minimum Height Trees

### Hard:
1. Critical Connections in a Network (Bridges)
2. Reconstruct Itinerary
3. Alien Dictionary (Topological Sort)
4. Bus Routes (BFS)
5. Word Ladder (BFS)
6. Cheapest Flights Within K Stops (Modified Dijkstra's/Bellman-Ford) 