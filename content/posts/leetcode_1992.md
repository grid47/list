
+++
authors = ["Crafted by Me"]
title = "Leetcode 1992: Find All Groups of Farmland"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1992: Find All Groups of Farmland in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-groups-of-farmland/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(land[i][j] == 1) {
                vector<int> tmp = {i, j, i, j};
                dfs(land, i, j, tmp);
               ans.push_back(tmp); 
            }

        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {

        if(land[i][j] != 1) return;
        
        land[i][j] = 0;
        
        tmp[2] = max(tmp[2], i);
        tmp[3] = max(tmp[3], j);
        
        if(j + 1 < n)
        dfs(land, i, j + 1, tmp);
            
        if(i + 1 < m)
        dfs(land, i + 1, j, tmp);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1992.md" >}}
---
{{< youtube R2mf-nBCWV4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1993: Operations on Tree](https://grid47.xyz/posts/leetcode_1993) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

