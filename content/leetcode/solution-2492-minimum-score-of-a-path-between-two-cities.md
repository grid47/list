
+++
authors = ["grid47"]
title = "Leetcode 2492: Minimum Score of a Path Between Two Cities"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2492: Minimum Score of a Path Between Two Cities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7epgOP3ezWM"
youtube_upload_date="2023-03-22"
youtube_thumbnail="https://i.ytimg.com/vi/7epgOP3ezWM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par;
    vector<int> mn;    
    UF(int n) {
        par.resize(n + 1);
        mn.resize(n + 1);        
        for(int i = 1; i < n + 1; i++) {
            par[i] = i;
            mn[i] = INT_MAX;
        }
    }
    
    bool uni(int x, int y, int n) {
        int p = find(x);
        int q = find(y);
        mn[p] = min({mn[p], mn[q], n});
        mn[q] = mn[p];
        if(p == q) return false;
        par[p] = q;
        return true;
    }
    int find(int x) {
        if(par[x] == x) return x;
        mn[x] = mn[find(par[x])];
        return par[x] = find(par[x]);
    }
    int mini(int x) {
        return mn[x];
    }
    bool check(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<vector<int>>> grid(n + 1);

        for(auto it: roads) {
            grid[it[0]].push_back({it[1], it[2]});
            grid[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> vis(n + 1, false); 
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int mn = INT_MAX;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                for(auto x: grid[it]) {
                        mn = min(mn, x[1]);                    
                    if(!vis[x[0]]) {
                        q.push(x[0]);
                        vis[x[0]] = true;
                    }
                }
            }
        }

        return mn;
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum score of a path between two nodes in a graph. The graph is represented by `n` nodes and a list of roads connecting pairs of nodes. Each road is characterized by its two endpoints and a score. The goal is to calculate the minimum score between node 1 and node `n`, considering all possible paths between these nodes.

### Approach

To solve this problem, we need to find the minimum score along the path from node `1` to node `n` across all possible roads. Since the problem involves a graph with weighted edges, we can use a **Breadth-First Search (BFS)** approach to explore the graph starting from node `1`. As we traverse through the graph, we need to track the minimum score of any edge we encounter.

The key insight here is that:
1. We need to explore the graph from node `1` and determine the smallest score among all roads that are part of any connected path to node `n`.
2. Since we need to calculate the minimum score between all paths, we should start from node `1` and traverse to all reachable nodes while tracking the minimum score of the roads.

### Code Breakdown (Step by Step)

#### 1. **Union-Find Data Structure (UF)**

```cpp
class UF {
    public:
    vector<int> par;
    vector<int> mn;
    
    UF(int n) {
        par.resize(n + 1);
        mn.resize(n + 1);
        for(int i = 1; i < n + 1; i++) {
            par[i] = i;
            mn[i] = INT_MAX;
        }
    }
    
    bool uni(int x, int y, int n) {
        int p = find(x);
        int q = find(y);
        mn[p] = min({mn[p], mn[q], n});
        mn[q] = mn[p];
        if(p == q) return false;
        par[p] = q;
        return true;
    }

    int find(int x) {
        if(par[x] == x) return x;
        mn[x] = mn[find(par[x])];
        return par[x] = find(par[x]);
    }

    int mini(int x) {
        return mn[x];
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }
};
```

- The `UF` (Union-Find) class is designed to manage the union and find operations efficiently. It helps to determine if two nodes belong to the same connected component.
- `par` is an array that keeps track of the parent of each node.
- `mn` keeps track of the minimum score within a connected component, initialized to `INT_MAX` to represent an initially unbounded score.
- The `find()` function is responsible for finding the representative (or parent) of a node while performing path compression to optimize future queries.
- The `uni()` function performs the union of two nodes, merging their components and updating the minimum score between them.
- The `mini()` function returns the minimum score in the connected component of a given node.
- The `check()` function determines whether two nodes are in the same connected component.

#### 2. **Graph Representation and BFS**

```cpp
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<vector<int>>> grid(n + 1);

        for(auto it: roads) {
            grid[it[0]].push_back({it[1], it[2]});
            grid[it[1]].push_back({it[0], it[2]});
        }
```

- First, we represent the graph using an adjacency list `grid`. Each node is connected to other nodes via roads, and each road has a score.
- The input `roads` consists of pairs of nodes with the score between them. The list is used to fill the adjacency list representation of the graph where each element `grid[i]` contains a list of pairs `[node, score]`, representing an edge from node `i` to another node with the corresponding score.

```cpp
        vector<int> vis(n + 1, false); 
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int mn = INT_MAX;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                for(auto x: grid[it]) {
                        mn = min(mn, x[1]);                    
                    if(!vis[x[0]]) {
                        q.push(x[0]);
                        vis[x[0]] = true;
                    }
                }
            }
        }

        return mn;
    }
};
```

- We initialize a `visited` array `vis` to track which nodes have been visited. We also initialize a queue `q` for BFS traversal, starting from node `1`.
- We perform BFS, exploring the graph from node `1`. For each node `it` that is dequeued:
  - We check all its neighboring nodes, and for each neighbor `x`, we update the minimum score `mn` encountered so far with the road score `x[1]`.
  - If the neighboring node `x[0]` hasn't been visited yet, we enqueue it for further exploration and mark it as visited.
- The BFS continues until all reachable nodes from node `1` have been visited, and we keep track of the minimum score encountered during the process.
- Once BFS completes, we return the minimum score encountered along any of the paths from node `1` to node `n`.

### Complexity Analysis

#### Time Complexity:
- **Building the adjacency list**: Constructing the graph takes **O(E)** time, where `E` is the number of edges (roads).
- **BFS Traversal**: The BFS process explores each node and edge at most once, resulting in **O(V + E)** time complexity, where `V` is the number of nodes and `E` is the number of edges.
- Therefore, the overall time complexity is **O(V + E)**, which is efficient for graph traversal problems.

#### Space Complexity:
- **Adjacency List**: The adjacency list requires **O(E)** space to store all the edges.
- **Visited Array**: The `visited` array requires **O(V)** space.
- **Queue**: The queue used for BFS requires **O(V)** space in the worst case.
- Thus, the overall space complexity is **O(V + E)**.

### Conclusion

The solution leverages **Breadth-First Search (BFS)** to explore the graph starting from node `1` and determine the minimum score among all paths to other nodes. This is achieved by maintaining a running minimum score as the BFS explores the roads. The approach ensures that we efficiently find the minimum score along the path between node `1` and any other reachable node.

The time complexity of **O(V + E)** makes the solution scalable for large graphs, and the space complexity of **O(V + E)** ensures the approach uses an optimal amount of memory for graph traversal.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/)

---
{{< youtube 7epgOP3ezWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
