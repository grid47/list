
+++
authors = ["grid47"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 802: Find Eventual Safe States in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp"
youtube = "Re_v0j0CRsg"
youtube_upload_date="2022-04-09"
youtube_thumbnail="https://i.ytimg.com/vi/Re_v0j0CRsg/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp" 
    alt="A graph with nodes marked as safe, glowing softly as they are identified."
    caption="Solution to LeetCode 802: Find Eventual Safe States Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> res;

        int n = graph.size();

        if(n == 0) return res;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++)
            if(dfs(graph, i, vis)) res.push_back(i);

        return res;
    }

    int dfs(vector<vector<int>>& graph, int cur, vector<int> &vis) {

        if(vis[cur] != 0) return vis[cur] == 2;

        vis[cur] = 1;
        for(auto nxt: graph[cur])
            if(!dfs(graph, nxt, vis)) return false;

        vis[cur] = 2;

        return true;
    }

};
{{< /highlight >}}
---

### Problem Statement
In this problem, we are given a directed graph, where each node represents a state, and each directed edge between nodes represents a possible transition from one state to another. The goal is to determine which nodes are "safe," meaning that starting from these nodes, you will eventually reach a terminal node or a node that has no outgoing edges. In other words, the task is to identify nodes from which no cycle can be reached, and if a cycle exists, the node is considered unsafe.

### Approach
To solve this problem, we need to determine which nodes are eventually safe. A node is considered safe if, starting from that node, the path eventually leads to a terminal node or a cycle-free path. In graph terms, we are looking for nodes that do not belong to any cycle.

To identify the safe nodes, we can use **Depth-First Search (DFS)** combined with state tracking:

1. **State Representation**:
   - **0**: The node has not been visited yet.
   - **1**: The node is currently in the DFS recursion stack (i.e., it is being explored).
   - **2**: The node is safe, meaning no cycles were found starting from this node.

2. **DFS Traversal**:
   - Start from a node and recursively visit its neighbors.
   - If a neighbor is part of the current DFS recursion (i.e., it is marked as **1**), a cycle is detected, and the node is unsafe.
   - If all neighbors of a node lead to safe nodes or terminal nodes, mark this node as safe.

3. **Result**:
   - We perform DFS on each node. If the node is eventually safe, we add it to the result list.

### Code Breakdown (Step by Step)

#### Step 1: Initial Setup
```cpp
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> res;
    int n = graph.size();
    if (n == 0) return res;
    vector<int> vis(n, 0);
```
- **`res`**: This vector will store the eventual safe nodes.
- **`n`**: This is the size of the graph (number of nodes).
- **`vis`**: A vector used to track the state of each node. Initially, all nodes are unvisited (marked as 0).

#### Step 2: DFS on Each Node
```cpp
    for (int i = 0; i < n; i++)
        if (dfs(graph, i, vis)) res.push_back(i);
```
- We loop through each node in the graph. For each node, we perform a DFS to determine if it is eventually safe. If it is, we add it to the result vector `res`.

#### Step 3: DFS Helper Function
```cpp
    int dfs(vector<vector<int>>& graph, int cur, vector<int>& vis) {
        if (vis[cur] != 0) return vis[cur] == 2;
        vis[cur] = 1;
        for (auto nxt : graph[cur])
            if (!dfs(graph, nxt, vis)) return false;
        vis[cur] = 2;
        return true;
    }
```
- **Base Case**: If a node has already been visited:
  - If the node is marked **2** (safe), return `true`.
  - If the node is marked **1** (in the current DFS stack), it means we've encountered a cycle, so we return `false`.
  
- **DFS Exploration**: Mark the current node as **1** (indicating it’s being visited). Then, recursively visit all its neighbors (outgoing edges). If any neighbor leads to an unsafe node (returning `false`), the current node is unsafe, and we return `false`.

- **Marking Safe Node**: Once all neighbors have been visited and are safe, mark the current node as **2** (safe) and return `true`.

#### Step 4: Return Result
Once all nodes have been processed, the `res` vector will contain the list of safe nodes. We return this vector.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(V + E)**, where:
- **V** is the number of nodes in the graph.
- **E** is the number of edges in the graph.

- **DFS Traversal**: Each node and edge is processed exactly once during the DFS traversal. Therefore, the overall time complexity is linear with respect to the number of nodes and edges in the graph.

#### Space Complexity:
The space complexity is **O(V)** because:
- We maintain the `vis` vector to track the state of each node, which requires space proportional to the number of nodes.
- The recursive call stack for DFS may also take up to **O(V)** space in the worst case.

### Conclusion

This solution efficiently identifies the eventual safe nodes in a directed graph using DFS. By maintaining a state for each node (unvisited, visiting, or safe), the algorithm ensures that each node is explored once, making the solution both time-efficient and space-efficient. The approach handles cycles in the graph by checking the DFS stack for back edges and ensures that only nodes that lead to safe states are considered safe.

This approach is optimal for this problem as it directly tracks the safety of nodes and leverages a standard graph traversal technique (DFS) to solve the problem in linear time with respect to the size of the graph. The overall design of the algorithm is simple, clean, and scalable, making it suitable for large graphs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-eventual-safe-states/description/)

---
{{< youtube Re_v0j0CRsg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
