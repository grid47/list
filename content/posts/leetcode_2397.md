
+++
authors = ["Crafted by Me"]
title = "Leetcode 2397: Maximum Rows Covered by Columns"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2397: Maximum Rows Covered by Columns in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-rows-covered-by-columns/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumRows(vector<vector<int>>& mtx, int sel) {
        int m = mtx.size(), n = mtx[0].size();
        
        int ans = 0;
        for(int msk = 0; msk < (1 << n); msk++) {
            if(__builtin_popcount(msk) != sel) continue;
            int res = 0;
            for(int i = 0; i < m; i++) {
                bool take = true;
                for(int j = 0; j < n; j++)
                    if(mtx[i][j] && (((msk >> j) & 1) == 0)) {
                        take = false;
                        break;
                    }
                if(take) res++;
            }
            ans = max(ans, res);
        }
        
        
        return ans;
    }

};
{{< /highlight >}}


---
{{< youtube scBL7uQiPMg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2398: Maximum Number of Robots Within Budget](https://grid47.xyz/posts/leetcode_2398) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

