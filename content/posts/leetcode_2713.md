
+++
authors = ["Crafted by Me"]
title = "Leetcode 2713: Maximum Strictly Increasing Cells in a Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2713: Maximum Strictly Increasing Cells in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Memoization","Sorting","Matrix","Ordered Set"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    int maxIncreasingCells(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();

        vector<int> row(m, 0), col(n, 0);
        
        map<int, vector<vector<int>>> mp;
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        set<int> item;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mp[-mat[i][j]].push_back({i, j});
            item.insert(-mat[i][j]);
        }
        
        for(int x : item) {
            
            for(auto v: mp[x]) {
                tmp[v[0]][v[1]] = max(row[v[0]], col[v[1]]) + 1;
            }
            
            for(auto v: mp[x]) {
                row[v[0]] = max(row[v[0]], tmp[v[0]][v[1]]);
                col[v[1]] = max(col[v[1]], tmp[v[0]][v[1]]);                
            }
            
        }
        
        return max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
    }    
};
{{< /highlight >}}


---
{{< youtube YBPv5GmTWb0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2714: Find Shortest Path with K Hops](https://grid47.xyz/posts/leetcode_2714) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

