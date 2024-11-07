
+++
authors = ["Crafted by Me"]
title = "Leetcode 2596: Check Knight Tour Configuration"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2596: Check Knight Tour Configuration in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-knight-tour-configuration/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        map<int, pair<int, int>> mp;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
        if(mp[0] != make_pair(0,0)) return false;
        int p = 0, q = 0;
        for(int i = 1; i < n * n; i++) {
            auto it = mp[i];
            int x = it.first;
            int y = it.second;
            if((abs(x - p) == 1 && abs(y - q) == 2) ||
               (abs(x - p) == 2 && abs(y - q) == 1)) {
                p = x;
                q = y;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2596.md" >}}
---
{{< youtube OBht8NT_09c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2597: The Number of Beautiful Subsets](https://grid47.xyz/posts/leetcode_2597) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
