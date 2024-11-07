
+++
authors = ["Crafted by Me"]
title = "Leetcode 1727: Largest Submatrix With Rearrangements"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1727: Largest Submatrix With Rearrangements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mtx) {
        int n = mtx[0].size(), m = mtx.size();
        vector<vector<int>> one(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if (mtx[j][i] == 1) { cnt++; } 
                else { cnt = 0; }
                one[j][i] = cnt;
            }
        }
        
        for(int i = 0; i < m; i++)
        sort(one[i].rbegin(), one[i].rend());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                res = max(res, one[i][j] * (j + 1));
                
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1727.md" >}}
---
{{< youtube NYyIVuSCfOA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1729: Find Followers Count](https://grid47.xyz/posts/leetcode_1729) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
