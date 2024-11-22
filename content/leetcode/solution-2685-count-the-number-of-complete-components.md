
+++
authors = ["grid47"]
title = "Leetcode 2685: Count the Number of Complete Components"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2685: Count the Number of Complete Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "J43LjwWYch4"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/J43LjwWYch4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par, edge, rnk;
    UF(int n) {
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        edge.resize(n, 0);
        rnk.resize(n, 1);
    }
    
    bool join(int i, int j) {
        int p = find(i);
        int q = find(j);
        if(p != q) {
            if(rnk[p] > rnk[q]) {
                rnk[p]+=rnk[q];
                par[q] = p;
            } else {
                rnk[q]+=rnk[p];
                par[p] = q;         
            }
            int e = edge[p]+edge[q] + 1;
            edge[p] =e; // dge[q] + 1;
            edge[q] =e; // dge[p] + 1;            
            return true;
        }
        edge[q]++;
        return false;
    }
    int find(int p) {
        if(p == par[p]) return p;
        return par[p] = find(par[p]);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UF uf = UF(n);
        for(auto e: edges) {
            uf.join(e[0], e[1]);
        }
        set<int> pk;
        int res = 0;
            // cout << "edges membercnt edgescal \n";         
        for(int i = 0; i < n; i++) {
            int par = uf.find(i);
            if(pk.count(par)) continue;
            pk.insert(par);
            int cnt = uf.edge[par];
            // cout << cnt << " " << uf.rnk[par] << " " << uf.rnk[par] * (uf.rnk[par] - 1) / 2 << "\n";
            if(uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the number of "complete components" in a graph, where a complete component is a connected component where the number of edges is exactly equal to the number of vertices minus one (i.e., the graph is a tree). A tree with `k` nodes always has `k-1` edges, so this is the key property for determining whether a component is a tree.

Given an undirected graph with `n` vertices and a list of `edges` that connect pairs of vertices, the task is to count how many connected components in the graph are "complete," meaning they form a tree.

### Approach

To solve this problem, we use the **Union-Find (Disjoint Set Union)** data structure, which helps efficiently manage and merge connected components in the graph. We extend this data structure to track the number of edges in each component, which is critical for determining whether a component is a tree. The approach can be broken down as follows:

1. **Union-Find Data Structure**: We need to efficiently find the parent of each node and merge two nodes into the same component. The union-find data structure supports two operations:
   - **Find**: To find the representative (or parent) of a node.
   - **Union**: To merge two components into one if they are not already connected.

2. **Tracking Edges**: Along with the parent, we also track the number of edges in each component, which is updated during the union operations.

3. **Checking for Complete Components**: After processing all the edges and merging components, we can check if each component is complete by verifying that the number of edges is exactly equal to the number of nodes in that component minus one.

### Code Breakdown (Step by Step)

#### Step 1: Union-Find (UF) Class Definition

```cpp
class UF {
public:
    vector<int> par, edge, rnk;
    UF(int n) {
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        edge.resize(n, 0);
        rnk.resize(n, 1);
    }
};
```

- The `UF` class represents the Union-Find data structure.
- `par` is a vector that stores the parent of each node. Initially, each node is its own parent.
- `edge` tracks the number of edges in each component.
- `rnk` is used for **union by rank**, which helps optimize the union operation by attaching the smaller tree to the root of the larger tree.

#### Step 2: The `join` Operation (Union)

```cpp
bool join(int i, int j) {
    int p = find(i);
    int q = find(j);
    if (p != q) {
        if (rnk[p] > rnk[q]) {
            rnk[p] += rnk[q];
            par[q] = p;
        } else {
            rnk[q] += rnk[p];
            par[p] = q;
        }
        int e = edge[p] + edge[q] + 1;
        edge[p] = e;
        edge[q] = e;
        return true;
    }
    edge[q]++;
    return false;
}
```

- The `join` method performs the union of two components `i` and `j`. If they are in different components, it merges them.
- **Union by rank**: The component with the higher rank becomes the parent of the other component. This helps keep the tree shallow, improving the efficiency of future operations.
- We also update the edge count for the merged components. If the components were already connected, we just increment the edge count of the parent.

#### Step 3: The `find` Operation (Find the Root of a Component)

```cpp
int find(int p) {
    if (p == par[p]) return p;
    return par[p] = find(par[p]);
}
```

- The `find` method uses path compression to find the representative (or root) of a component.
- Path compression ensures that all nodes directly point to the root, optimizing future find operations.

#### Step 4: The `countCompleteComponents` Method

```cpp
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    UF uf = UF(n);
    for (auto e : edges) {
        uf.join(e[0], e[1]);
    }
    set<int> pk;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int par = uf.find(i);
        if (pk.count(par)) continue;
        pk.insert(par);
        int cnt = uf.edge[par];
        if (uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
    }
    return res;
}
```

- The `countCompleteComponents` method initializes the Union-Find structure with `n` vertices.
- For each edge in the input, the `join` method is called to connect the vertices, updating the components' edge counts.
- We then check each component to see if it forms a complete tree:
  - A component is complete if the number of edges is equal to the number of vertices minus one. This condition is checked using the formula `rnk[par] * (rnk[par] - 1) / 2 == cnt`, where `rnk[par]` is the size of the component and `cnt` is the number of edges.
- If a component satisfies this condition, it is considered a complete component, and we increment the result counter.
- Finally, the method returns the count of complete components.

### Complexity

#### Time Complexity

- The time complexity of the Union-Find operations is nearly constant, thanks to the **union by rank** and **path compression** optimizations. The amortized time complexity for each `find` and `join` operation is **O(α(n))**, where α is the **inverse Ackermann function**, which grows very slowly.
- For `m` edges and `n` vertices, the overall time complexity is **O(m * α(n))**.

#### Space Complexity

- The space complexity is **O(n)**, as we store the parent (`par`), edge count (`edge`), and rank (`rnk`) arrays, each of size `n`.

### Conclusion

This solution efficiently solves the problem using the Union-Find data structure, which allows us to handle the merging and checking of connected components in near constant time. By tracking both the parent and the number of edges in each component, we can easily determine whether a component is a tree (i.e., has exactly `n-1` edges). The approach is optimized with **union by rank** and **path compression**, ensuring that the solution scales well even for large graphs. The complexity of the solution is manageable and performs well within the problem's constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-complete-components/description/)

---
{{< youtube J43LjwWYch4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
