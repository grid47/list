
+++
authors = ["grid47"]
title = "Leetcode 1361: Validate Binary Tree Nodes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1361: Validate Binary Tree Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Union Find","Graph","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Mw67DTgUEqk"
youtube_upload_date="2023-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/Mw67DTgUEqk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class UF {
    
    public:
    
    vector<int> chd, rnk;
    int net;
    
    UF (int n) {
        chd.resize(n);
        rnk.resize(n, 0);
        for(int i = 0; i < n; i++) {
            chd[i] = i; }
        net = n;
    }
    
    bool uni(int i, int j) {
        int x = find(i);
        int y = find(j);
        if((x == y) || (y != j)) return false;
        
        chd[y] = x;
        net--;
        
       /* if(x != y) {
            if(rnk[x] < rnk[y]) {
                
                chd[x] = y;
                rnk[y]++;
                
            } else {
                
                chd[y] = x;
                rnk[x]++;
                
            }
            net--;
            return true;
        }
        cout << x << y;*/
       return true;
    }
    
    int find(int x) {
        if(chd[x] != x) {
           chd[x] = find(chd[x]);
        }
        return chd[x];
    }
    
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        UF uf = UF(n);
        for(int i = 0; i < n; i++) {
            if(lc[i] >= 0) {
                
if(!uf.uni(i, lc[i])) 
    return false; 
                
            }
            if(rc[i] >= 0) {
 
if(!uf.uni(i, rc[i])) 
    return false; 
                
            }
        }
        cout << uf.net;
        return uf.net == 1;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem involves validating a binary tree structure given the number of nodes and their respective left and right children. Each node in the tree is represented by its index, and the input includes two arrays, `lc` and `rc`, which represent the left and right children of each node, respectively. The task is to determine whether these nodes form a valid binary tree, meaning:
1. There should be exactly one root node (no cycles).
2. Each node should have at most one parent (no two nodes should point to the same child).
3. The tree should contain all `n` nodes with no unconnected nodes.

### Approach
To validate the binary tree, we can utilize the union-find data structure, which efficiently handles merging and finding components within a set. The main steps are:
1. **Initialize Union-Find Structure**: Create a union-find structure to manage the nodes and track their connected components.
2. **Union Operations**: For each node, perform union operations for its left and right children, ensuring that no cycles are formed and no node has more than one parent.
3. **Check Conditions**: After processing all nodes, check if there is exactly one connected component, which would indicate the presence of a valid binary tree.

### Code Breakdown (Step by Step)

```cpp
class UF {
public:
    vector<int> chd, rnk; // chd: parent pointers; rnk: rank for union by rank
    int net; // number of components
    
    UF(int n) {
        chd.resize(n); // Resize the child vector
        rnk.resize(n, 0); // Initialize rank vector with zero
        for (int i = 0; i < n; i++) {
            chd[i] = i; // Each node is its own parent initially
        }
        net = n; // Initially, there are n components
    }
    
    bool uni(int i, int j) {
        int x = find(i); // Find the root of i
        int y = find(j); // Find the root of j
        if (x == y) return false; // If they are already connected, return false
        
        chd[y] = x; // Connect the two components
        net--; // Reduce the number of components
        return true;
    }
    
    int find(int x) {
        if (chd[x] != x) {
            chd[x] = find(chd[x]); // Path compression
        }
        return chd[x]; // Return the root of the component
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        UF uf = UF(n); // Initialize union-find structure with n nodes
        for (int i = 0; i < n; i++) {
            if (lc[i] >= 0) {
                if (!uf.uni(i, lc[i])) // Union current node with left child
                    return false; 
            }
            if (rc[i] >= 0) {
                if (!uf.uni(i, rc[i])) // Union current node with right child
                    return false; 
            }
        }
        return uf.net == 1; // Check if there is exactly one component
    }
};
```

1. **Union-Find Class (UF)**:
   - The `UF` class initializes two vectors: `chd` to maintain parent-child relationships and `rnk` to manage the rank for union operations. It also keeps track of the number of components (initially set to `n`).
   - The `uni` method connects two nodes, decrementing the component count if they are successfully united.
   - The `find` method retrieves the root of the node, using path compression to flatten the structure and speed up future queries.

2. **Solution Class**:
   - The `validateBinaryTreeNodes` method initializes a union-find structure for `n` nodes.
   - It iterates over each node to perform union operations with its left and right children (if they exist). If any union operation fails (indicating a cycle or multiple parents), the method returns `false`.
   - Finally, it checks if there is exactly one component left, which confirms that the structure is a valid binary tree.

### Complexity Analysis
- **Time Complexity**:
  - The time complexity is \(O(n \cdot \alpha(n))\), where \(\alpha\) is the inverse Ackermann function. This is effectively constant time for practical input sizes, due to the efficiency of the union-find operations.
  
- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the storage used for the `chd` and `rnk` vectors.

### Conclusion
The `validateBinaryTreeNodes` method effectively uses the union-find data structure to determine whether a given set of nodes and their respective children can form a valid binary tree. By ensuring that each node adheres to the constraints of having only one parent and connecting all nodes into a single component, the solution provides a robust approach to validating tree structures. The implementation demonstrates the utility of union-find in graph-related problems, particularly in maintaining component connectivity efficiently.

This explanation serves as a comprehensive guide for understanding the algorithm and its implementation, making it a valuable resource for both beginners and experienced programmers looking to deepen their understanding of tree validation using union-find techniques.


[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-binary-tree-nodes/description/)

---
{{< youtube Mw67DTgUEqk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
