
+++
authors = ["grid47"]
title = "Leetcode 684: Redundant Connection"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 684: Redundant Connection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp"
youtube = "FXWRE67PLL0"
youtube_upload_date="2021-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/FXWRE67PLL0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp" 
    alt="A graph where redundant connections are detected and softly glowing to indicate the loop."
    caption="Solution to LeetCode 684: Redundant Connection Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF* uf = new UF(n);
        for(int i = 0; i < n; i++)
            if(!uf->uni(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        return edges[0];
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem at hand is to find the redundant edge in an undirected graph represented by a list of edges. This graph has `n` nodes and `n-1` edges, forming a tree. However, one of the edges has been added redundantly, creating a cycle. The goal is to identify this redundant edge in the graph.

Given a graph as a list of edges, each edge is represented as an array `[u, v]`, where `u` and `v` are the nodes connected by the edge. We need to identify the edge that, if removed, will eliminate the cycle and return that edge.

### Approach:
To solve the problem of finding the redundant edge in an undirected graph, we can utilize a **Union-Find (Disjoint Set Union - DSU)** data structure. This data structure allows us to efficiently track connected components in the graph. The main idea is to iterate through all edges and for each edge:
1. If the two nodes connected by the edge are already in the same connected component (i.e., they belong to the same set), then adding this edge would create a cycle, and this edge is the redundant one.
2. If the nodes are in different components, we unite them into a single component.

By using this approach, we can detect cycles in an efficient manner while processing the edges. The algorithm works in nearly constant time due to the optimized union-find operations, making it suitable for large graphs.

### Code Breakdown (Step by Step):

#### Step 1: Union-Find Data Structure (UF Class)
```cpp
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};
```
- The `UF` class is used to represent the Union-Find data structure. It maintains an array `chd` to track the parent of each node. Initially, each node is its own parent.
- `cnt` tracks the number of connected components (sets) in the graph.
- The constructor `UF(int n)` initializes the `chd` array and sets each node to be its own parent, effectively creating `n` connected components.

#### Step 2: `uni` Method (Union Operation)
```cpp
bool uni(int x, int y) {
    int i = find(x);  // Find the root of the set containing x
    int j = find(y);  // Find the root of the set containing y
    if(i != j) {  // If they are in different sets
        chd[i] = j;  // Unite the sets by linking the root of x to the root of y
        cnt--;  // Decrease the number of connected components
        return true;
    } else return false;  // If they are already in the same set, return false (cycle detected)
}
```
- The `uni` function takes two nodes `x` and `y` and attempts to unite the sets they belong to. If the two nodes are already in the same set, it means adding the edge between them would form a cycle, so the function returns `false`. Otherwise, it unites the sets and returns `true`.

#### Step 3: `find` Method (Find Operation with Path Compression)
```cpp
int find(int x) {
    if(x == chd[x]) return x;  // If x is its own parent, it's the root of the set
    return chd[x] = find(chd[x]);  // Path compression: recursively find the root and make x point directly to it
}
```
- The `find` function recursively finds the root of the set containing `x`. It also performs **path compression** to flatten the structure of the tree, speeding up future queries.

#### Step 4: Main Solution (`findRedundantConnection` Method)
```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF* uf = new UF(n);  // Initialize the Union-Find structure with n nodes
        for(int i = 0; i < n; i++)
            if(!uf->uni(edges[i][0], edges[i][1])) {  // If the edge forms a cycle
                return edges[i];  // Return the redundant edge
            }
        return edges[0];  // Default return (this will not be hit in practice)
    }
};
```
- The main function `findRedundantConnection` takes the `edges` of the graph as input and creates a Union-Find structure `uf` with `n` nodes.
- It iterates over all the edges in the graph. For each edge, it checks if the nodes are already connected using the `uni` method:
  - If `uni` returns `false`, it means the nodes are already connected, indicating that adding the edge would create a cycle. Therefore, the current edge is the redundant one, and we return it.
  - If the edge does not create a cycle, we proceed to the next edge.
- The algorithm terminates as soon as it finds the redundant edge.

### Complexity:

#### Time Complexity:
- **O(n * α(n))**, where `n` is the number of edges and `α(n)` is the inverse Ackermann function. The Union-Find operations (`find` and `uni`) take nearly constant time due to the **path compression** and **union by rank** techniques.
- The total time complexity is dominated by the number of edges, which is `n` (since the number of nodes is typically proportional to the number of edges).

#### Space Complexity:
- **O(n)**, where `n` is the number of nodes. The Union-Find data structure stores an array of size `n` to track the parent of each node.

### Conclusion:
The provided solution efficiently detects the redundant edge in a graph by utilizing the Union-Find data structure with path compression. This approach ensures that we can process the graph in nearly constant time for each edge. The solution works optimally for large graphs and provides a clear and effective way to identify the redundant edge that creates a cycle.

By using the Union-Find algorithm with its optimization techniques, such as path compression and union by rank, we can handle the problem of cycle detection in graphs with high efficiency. This solution is optimal for scenarios where the graph has a large number of edges, and it provides a fast and scalable method for solving the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/redundant-connection/description/)

---
{{< youtube FXWRE67PLL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
