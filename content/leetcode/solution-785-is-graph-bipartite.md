
+++
authors = ["grid47"]
title = "Leetcode 785: Is Graph Bipartite?"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 785: Is Graph Bipartite? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp"
youtube = "j69Of_2nfRA"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/j69Of_2nfRA/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp" 
    alt="A graph where bipartiteness is checked, with the two sets glowing softly as they are separated."
    caption="Solution to LeetCode 785: Is Graph Bipartite? Problem"
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
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();
          UF* uf = new UF(n);

        for(int i = 0; i < n; i++) {
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

The problem at hand involves determining whether a graph is **bipartite**. A bipartite graph is one in which the set of vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. The goal is to return `true` if the graph is bipartite and `false` otherwise.

The graph is given as an adjacency list, where each element in the list represents a vertex, and the list of integers associated with that element represents the neighbors of that vertex.

### Approach

To check whether the graph is bipartite, we can treat the problem as one of coloring the graph. The idea is to attempt to color each vertex with one of two colors, ensuring that adjacent vertices have different colors. If we find two adjacent vertices with the same color, the graph is not bipartite.

This problem can be efficiently solved using **Union-Find** (also known as Disjoint-Set Union, or DSU), which is a data structure that helps efficiently track and manage the connected components of a graph.

### Key Concepts of Union-Find:
1. **Union**: This operation merges two sets into one. It connects two elements together, meaning they belong to the same set.
2. **Find**: This operation determines the root of the set to which an element belongs. It is used to determine if two elements are in the same set.
3. **Path Compression**: This technique optimizes the `find` operation, ensuring that the trees representing sets remain flat and make subsequent find operations faster.
4. **Union by Rank/Size**: This technique helps optimize the `union` operation by attaching the smaller tree under the root of the larger tree, keeping the set tree structure balanced.

By applying Union-Find, we can track the connected components and ensure that no two vertices within the same component share the same color, thus confirming whether the graph is bipartite.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

#### Step 1: Union-Find Data Structure Implementation

```cpp
class UF {
public:
    vector<int> chd;
    int cnt;

    UF(int n) {
        chd.resize(n, 0);
        for(int i = 0; i < n; i++)
            chd[i] = i;  // Each node starts as its own parent
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);  // Find root of x
        int j = find(y);  // Find root of y
        if(i != j) {  // If roots are different, perform union
            chd[i] = j;  // Make one root the parent of the other
            cnt--;  // Decrease number of disjoint sets
            return true;
        } else {
            return false;  // If they are already in the same set, no need to union
        }
    }

    int find(int x) {
        if(x == chd[x]) return x;  // If x is its own parent, it's the root
        return chd[x] = find(chd[x]);  // Path compression
    }
};
```

1. **Constructor**: Initializes the Union-Find data structure with `n` elements. Initially, each element is its own parent (i.e., each element forms its own set).
2. **Union (uni)**: This function merges two sets, `x` and `y`, if they are not already in the same set. It reduces the count of disjoint sets and ensures that the two sets are connected.
3. **Find**: This function returns the root of the set containing element `x`. It also applies path compression to make future queries faster.

#### Step 2: Main Solution to Check Bipartiteness

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();  // Number of vertices in the graph
        UF* uf = new UF(n);  // Create a Union-Find data structure to track connected components

        for(int i = 0; i < n; i++) {
            for(int x: gph[i]) {  // Iterate over the neighbors of vertex i
                if(uf->find(x) == uf->find(i))  // If the neighbors are already in the same set, return false
                    return false;
                uf->uni(gph[i][0], x);  // Union the current vertex and its neighbor
            }
        }
        return true;  // If no conflicts are found, the graph is bipartite
    }
};
```

1. **Graph Input**: The graph is given as an adjacency list, `gph`, where each index in the list represents a vertex, and its value is a list of its neighboring vertices.
   
2. **Union-Find Setup**: 
   - A new instance of the `UF` class is created, initialized with the number of vertices, `n`.
   - We use this instance to track which vertices are in the same set.

3. **Main Loop**: We loop over each vertex `i`:
   - For each vertex `i`, we loop through its neighbors (`gph[i]`).
   - If a neighbor is already in the same set as `i` (i.e., both share the same root), we return `false`, indicating that the graph cannot be bipartite.
   - If the vertex and its neighbor are not in the same set, we perform the `uni` operation to merge their sets.

4. **Return Value**: If no conflicts (same-set neighbors) are found, the graph is bipartite, and we return `true`.

### Complexity Analysis

- **Time Complexity**:
  - **Union-Find Operations**: Both `find` and `union` operations are nearly constant time, i.e., O(α(n)), where α is the inverse Ackermann function, which grows very slowly. Therefore, these operations are practically O(1) for all practical inputs.
  - **Graph Traversal**: We iterate through all vertices and their neighbors. In the worst case, this takes O(V + E) time, where V is the number of vertices and E is the number of edges in the graph.
  - Overall time complexity is O(V + E), which is efficient for graph traversal problems.

- **Space Complexity**:
  - The space complexity is O(V), as we store the parent array in the Union-Find data structure and need to keep track of the graph’s adjacency list.
  - The overall space complexity is linear in terms of the number of vertices and edges.

### Conclusion

This solution uses the Union-Find data structure to check whether a graph is bipartite. By leveraging the union and find operations, we ensure that the graph can be divided into two disjoint sets where no two adjacent vertices belong to the same set. This approach is both time and space-efficient, making it suitable for large graphs.

#### Key Takeaways:
- The Union-Find data structure is an excellent choice for managing connected components in a graph.
- Path compression and union by rank optimize the performance of the `find` and `union` operations, making the solution scalable for large inputs.
- The algorithm efficiently checks for bipartiteness in a graph by ensuring that adjacent vertices have different sets (colors).


[`Link to LeetCode Lab`](https://leetcode.com/problems/is-graph-bipartite/description/)

---
{{< youtube j69Of_2nfRA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
