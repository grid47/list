
+++
authors = ["grid47"]
title = "Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2FIK7F0Qs38"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi/2FIK7F0Qs38/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    long long countPairs(int n, vector<vector<int>>& es) {
        
        vector<vector<int>> g(n, vector<int>());
        for(vector<int> e: es){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            
        }
        vector<bool> vis(n, false);
        ll res = (ll) n * (n - 1) /2;
            
        for(int i = 0; i < n; i++) {
            ll ret = 0;
      if(!vis[i])
      ret = dfs(i, g, vis);
      res -= (ret * (ret -1)/2);
        }
        
        return res;
        
    }
    
    ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
        
        if(vis[i]) return 0;
        vis[i] = true;
        ll res = 1;
        for(int v : g[i]) {
            res += dfs(v, g, vis);
        }
        return res;
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the number of pairs of nodes in a graph that are not connected by an edge. We are given an undirected graph with `n` nodes and `m` edges, and we need to determine the number of pairs of nodes that are not connected either directly or indirectly through other nodes (i.e., not part of the same connected component).

### Approach

The approach to solving this problem involves:
1. **Graph Construction**: Constructing an adjacency list to represent the graph from the input edges.
2. **DFS for Connected Components**: Using Depth-First Search (DFS) to traverse the graph and identify connected components. Each connected component is a subset of nodes where every pair of nodes is reachable either directly or through other nodes.
3. **Counting Pairs**: The total number of pairs of nodes in the graph can be calculated as `n * (n - 1) / 2`. Once we have the sizes of the connected components, we can calculate the number of pairs within each connected component and subtract them from the total number of pairs.

#### Key Ideas:
- **Total Pairs**: The total number of possible pairs of nodes in the graph is given by the formula `n * (n - 1) / 2`, where `n` is the number of nodes.
- **Connected Pairs**: For each connected component, the number of pairs within that component can be calculated using the formula `size * (size - 1) / 2`, where `size` is the number of nodes in that component. These pairs are **connected**.
- **Disconnected Pairs**: The number of pairs that are not connected is the total number of pairs minus the number of connected pairs.

### Code Breakdown (Step by Step)

#### Step 1: Graph Representation
```cpp
vector<vector<int>> g(n, vector<int>());
for (vector<int> e : es) {
    g[e[0]].push_back(e[1]);
    g[e[1]].push_back(e[0]);
}
```
- We create an adjacency list `g` where `g[i]` contains a list of nodes that are directly connected to node `i`. The input edges are used to populate this adjacency list. For each edge `[u, v]`, we add `v` to the adjacency list of `u`, and vice versa because the graph is undirected.

#### Step 2: Initialize Variables
```cpp
vector<bool> vis(n, false);
ll res = (ll)n * (n - 1) / 2;
```
- **`vis`**: A boolean vector `vis` is used to keep track of which nodes have been visited during the DFS traversal.
- **`res`**: The initial number of total pairs of nodes is calculated as `n * (n - 1) / 2`, where `n` is the number of nodes in the graph. This is the upper bound, i.e., the number of possible pairs if no nodes were connected.

#### Step 3: DFS Traversal to Find Connected Components
```cpp
for (int i = 0; i < n; i++) {
    ll ret = 0;
    if (!vis[i])
        ret = dfs(i, g, vis);
    res -= (ret * (ret - 1) / 2);
}
```
- We iterate through each node `i`. If it has not been visited (`!vis[i]`), we perform a DFS traversal starting from `i`.
- The result from DFS (`ret`) is the size of the connected component that includes node `i`.
- The number of connected pairs within this component is calculated as `ret * (ret - 1) / 2`, and this is subtracted from the total number of pairs (`res`).

#### Step 4: DFS Function to Compute Component Size
```cpp
ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
    if (vis[i]) return 0;
    vis[i] = true;
    ll res = 1;
    for (int v : g[i]) {
        res += dfs(v, g, vis);
    }
    return res;
}
```
- The DFS function starts from node `i` and explores all nodes that are reachable from `i` (i.e., all nodes in the same connected component).
- **`res`**: The `res` variable keeps track of the size of the connected component.
- We recursively call DFS on all neighbors of the current node. For each unvisited neighbor `v`, the size of the connected component is increased by calling `dfs(v, g, vis)` and adding the result.

#### Step 5: Return Final Result
```cpp
return res;
```
- After processing all nodes, the final value of `res` represents the number of pairs of nodes that are not connected directly or indirectly.

### Complexity

#### Time Complexity:
- **Graph Construction**: Building the adjacency list takes **O(m)** time, where `m` is the number of edges.
- **DFS Traversal**: Each node and edge is visited exactly once during the DFS, so the DFS traversal takes **O(n + m)** time.
- Therefore, the total time complexity is **O(n + m)**, which is optimal for this problem.

#### Space Complexity:
- **Adjacency List**: Storing the graph requires **O(n + m)** space.
- **Visited Array**: The `vis` array requires **O(n)** space.
- **Recursion Stack**: In the worst case, the recursion stack for DFS can go as deep as the number of nodes in the graph, requiring **O(n)** space.
- Therefore, the total space complexity is **O(n + m)**.

### Conclusion

The algorithm solves the problem efficiently by first building the graph using an adjacency list and then performing a DFS traversal to find the sizes of the connected components. The number of pairs of nodes that are not connected is then calculated by subtracting the number of connected pairs from the total possible pairs. The solution runs in linear time relative to the size of the graph, making it well-suited for large inputs. The space complexity is also optimal, using only a few additional data structures for storing the graph and tracking visited nodes.

This approach leverages Depth-First Search (DFS) to identify connected components, making it a robust and effective method for solving graph-related problems involving connectivity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

---
{{< youtube 2FIK7F0Qs38 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
