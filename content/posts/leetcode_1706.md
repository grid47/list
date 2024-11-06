
+++
authors = ["Crafted by Me"]
title = "Leetcode 1706: Where Will the Ball Fall"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1706: Where Will the Ball Fall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/where-will-the-ball-fall/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < n; i++) {
            int i1 = i, i2;
            for(int j = 0; j < m; j++) {
                i2 = i1 + grid[j][i1];
                if(i2 <0 || i2 >= n || grid[j][i1] != grid[j][i2]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res.push_back(i1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1706.md" >}}
---
{{< youtube QydaN-AVEAA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1707: Maximum XOR With an Element From Array](https://grid47.xyz/posts/leetcode_1707) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
