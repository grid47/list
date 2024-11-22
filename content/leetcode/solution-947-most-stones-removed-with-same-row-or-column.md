
+++
authors = ["grid47"]
title = "Leetcode 947: Most Stones Removed with Same Row or Column"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 947: Most Stones Removed with Same Row or Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Depth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kLUgZzUKEK0"
youtube_upload_date="2020-10-30"
youtube_thumbnail="https://i.ytimg.com/vi/kLUgZzUKEK0/maxresdefault.jpg"
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UF* uf = new UF(n);
        map<int, int> x, y;
        for(int i = 0; i < n; i++) {
            int p = stones[i][0];
            int q = stones[i][1];
            if(x.count(p)) {
                uf->uni(x[p], i);
            }
            if(y.count(q)) {
                uf->uni(y[q], i);
            }
            x[p] = i;
            y[q] = i;
        }
        return n - uf->cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the maximum number of stones that can be removed from a grid, given that stones are positioned at specific coordinates. The removal condition is that two stones can be removed if they lie on the same row or the same column. The goal is to find the maximum number of stones that can be removed, leaving only the minimum number of stones behind.

### Approach

To solve this problem, we can model the situation as a graph where each stone is a node. There will be an edge between two stones if they share the same row or column. The problem then becomes one of finding connected components in this graph. Stones within the same connected component can all be removed, since they are either directly or indirectly connected through shared rows or columns.

We can use the **Union-Find (UF)** data structure to efficiently handle the connected components. The steps involved are as follows:

1. **Initialization**:
   - For each stone, we associate it with its coordinates. Stones in the same row or column will be linked by a union operation.

2. **Union-Find Data Structure**:
   - We will use the Union-Find data structure to group stones that can be connected through their rows and columns. The idea is that if two stones share the same row or column, they belong to the same connected component.

3. **Mapping Stones by Row and Column**:
   - We create maps to track the most recent stone in each row and column. If a stone shares the same row or column with an already seen stone, we will perform a union operation between them, ensuring they are in the same connected component.

4. **Counting Components**:
   - After processing all the stones, the number of connected components will be the number of stones that cannot be removed (i.e., the minimum stones left). The maximum number of stones that can be removed will be the total number of stones minus the number of connected components.

### Code Breakdown (Step by Step)

1. **Union-Find Class**:
   ```cpp
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
   ```
   - This `UF` class manages the Union-Find data structure, with methods for finding the root of a node (`find`) and uniting two nodes (`uni`). The `cnt` variable tracks the number of connected components.

2. **Solution Class and the `removeStones` Function**:
   ```cpp
   class Solution {
   public:
       int removeStones(vector<vector<int>>& stones) {
           int n = stones.size();
           UF* uf = new UF(n);  // Initialize Union-Find with n stones
           map<int, int> x, y;  // Maps to track the last stone in each row and column
           
           // Process each stone
           for(int i = 0; i < n; i++) {
               int p = stones[i][0];
               int q = stones[i][1];
               
               // Union stones in the same row
               if(x.count(p)) {
                   uf->uni(x[p], i);
               }
               // Union stones in the same column
               if(y.count(q)) {
                   uf->uni(y[q], i);
               }
               
               // Update the row and column mappings
               x[p] = i;
               y[q] = i;
           }
           
           // The number of stones that cannot be removed is the number of components
           return n - uf->cnt;  // The result is total stones minus the number of components
       }
   };
   ```
   - **Union and Mapping**:
     - For each stone at position `(p, q)`, we check if there is a previously seen stone in the same row `p` or column `q`. If there is, we union the current stone with the previously seen stone, effectively marking them as part of the same connected component.
   
   - **Tracking Components**:
     - The `x` and `y` maps help track the last seen stone for each row and column. If a stone shares a row or column with a previously processed stone, we perform the union operation to ensure they are part of the same component.
   
   - **Result Calculation**:
     - The total number of stones minus the number of connected components (`uf->cnt`) gives the maximum number of stones that can be removed.

### Complexity

1. **Time Complexity**:
   - **Union-Find Operations**: The `find` and `union` operations take almost constant time due to path compression and union by rank. These operations are effectively O(α(n)), where α is the inverse Ackermann function, which grows very slowly.
   - **Loop Over Stones**: We process each stone once, and for each stone, we perform constant-time operations (checking and updating the maps, performing union operations).
   - Overall, the time complexity is O(n), where `n` is the number of stones.

2. **Space Complexity**:
   - The space complexity is O(n) for storing the Union-Find data structure and the `x` and `y` maps.

### Conclusion

This solution efficiently solves the problem by modeling it as a graph problem and using the Union-Find data structure to handle connected components. By uniting stones that are in the same row or column, the algorithm effectively determines the number of connected components, and from that, computes the maximum number of stones that can be removed. The Union-Find operations ensure that the solution runs efficiently, even for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/)

---
{{< youtube kLUgZzUKEK0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
