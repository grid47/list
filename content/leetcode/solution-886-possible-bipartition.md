
+++
authors = ["grid47"]
title = "Leetcode 886: Possible Bipartition"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 886: Possible Bipartition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WIJa0GAC9Cg"
youtube_upload_date="2020-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/WIJa0GAC9Cg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n, 0);
        for(int i = 0; i < n; i++)
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
    bool possibleBipartition(int n, vector<vector<int>>& dlk) {
        UF* uf = new UF(n + 1);
        vector<vector<int>> gph(n + 1);
        for(int i = 0; i < dlk.size(); i++) {
            gph[dlk[i][0]].push_back(dlk[i][1]);
            gph[dlk[i][1]].push_back(dlk[i][0]);            
        }

        for(int i = 1; i <= n; i++) {
            for(int x: gph[i]) {
                if(uf->find(x) == uf->find(i)) return false;
                uf->uni(gph[i][0], x);
            }
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks whether it is possible to divide a group of `n` people into two groups such that no two people who dislike each other are in the same group. Each person is identified by an integer from 1 to `n`, and a list of dislikes between pairs of people is provided. The goal is to determine if a valid bipartition (division into two groups) exists such that all pairs of people who dislike each other end up in separate groups.

### Approach

This problem is a typical graph bipartition problem, where the goal is to determine whether a graph is bipartite. A graph is bipartite if we can divide its set of vertices into two disjoint sets such that no two vertices within the same set are adjacent.

In this problem:
- Each person is a node.
- A dislike relationship between two people is represented by an undirected edge between two nodes.
- The task is to check whether it's possible to color this graph with two colors such that no two adjacent nodes (people who dislike each other) have the same color.

We can solve this problem using a **Union-Find** (also known as **Disjoint Set Union - DSU**) data structure, which efficiently supports the operations of finding the parent of a node and merging two sets. The strategy is:
1. Use Union-Find to track connected components of the graph.
2. If two people dislike each other, they must belong to different sets.
3. If we ever find that two people who dislike each other are in the same set, then the graph is not bipartite, and we return `false`.

### Code Breakdown (Step by Step)

#### **Union-Find Data Structure (UF Class)**

1. **Initialization**:
   ```cpp
   UF(int n) {
       chd.resize(n, 0);
       for(int i = 0; i < n; i++)
           chd[i] = i;
       cnt = n;
   }
   ```
   The `UF` class is initialized with `n` elements. The `chd` vector stores the parent for each node, initially setting each node as its own parent (i.e., each node is its own representative in the set). The `cnt` variable tracks the number of disjoint sets.

2. **Find Operation**:
   ```cpp
   int find(int x) {
       if(x == chd[x]) return x;
       return chd[x] = find(chd[x]);
   }
   ```
   The `find` function recursively finds the root of the set that `x` belongs to. It uses path compression, meaning that it flattens the structure of the tree to make future queries faster.

3. **Union Operation**:
   ```cpp
   bool uni(int x, int y) {
       int i = find(x);
       int j = find(y);
       if(i != j) {
           chd[i] = j;
           cnt--;
           return true;
       } else return false;
   }
   ```
   The `uni` function connects two nodes `x` and `y`. If `x` and `y` are not already in the same set, it merges their sets by making `x`'s root point to `y`'s root and decreases the count of disjoint sets. If `x` and `y` are already in the same set, it returns `false`.

#### **Main Solution (possibleBipartition Function)**

1. **Graph Representation**:
   ```cpp
   vector<vector<int>> gph(n + 1);
   for(int i = 0; i < dlk.size(); i++) {
       gph[dlk[i][0]].push_back(dlk[i][1]);
       gph[dlk[i][1]].push_back(dlk[i][0]);            
   }
   ```
   The function starts by building an adjacency list `gph` from the list of dislikes. This list represents an undirected graph where each person (node) is connected to other people (nodes) they dislike.

2. **Union-Find Traversal**:
   ```cpp
   for(int i = 1; i <= n; i++) {
       for(int x: gph[i]) {
           if(uf->find(x) == uf->find(i)) return false;
           uf->uni(gph[i][0], x);
       }
   }
   ```
   The main traversal begins with each person `i`. For each person `i`, the algorithm checks all their disliked people (adjacent nodes in the graph). If two people who dislike each other belong to the same set (i.e., they are in the same group), it returns `false` because this violates the bipartition condition.

   If the two people who dislike each other are in different sets, we use the `union` operation to connect them, effectively marking them as belonging to opposite groups.

3. **Return Statement**:
   ```cpp
   return true;
   ```
   If no conflicts are found during the entire traversal, it means that the bipartition is possible, and the function returns `true`.

### Complexity

The time complexity of the solution is **O((n + m) * α(n))**, where:
- `n` is the number of people.
- `m` is the number of dislike pairs.
- `α(n)` is the inverse Ackermann function, which grows very slowly, making the union-find operations effectively constant time for practical purposes.

Thus, the solution is highly efficient, even for larger values of `n` and `m`.

The space complexity is **O(n + m)** due to the adjacency list used to represent the graph and the `UF` data structure.

### Conclusion

This solution effectively solves the bipartition problem by leveraging the Union-Find data structure, ensuring that it can efficiently track the connected components and check for conflicts in the bipartition. The use of path compression and union by rank in the Union-Find operations makes the solution optimal for large inputs. The approach guarantees that we can determine whether it's possible to divide the group into two disjoint sets where no two people who dislike each other end up in the same set.

[`Link to LeetCode Lab`](https://leetcode.com/problems/possible-bipartition/description/)

---
{{< youtube WIJa0GAC9Cg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
