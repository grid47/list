
+++
authors = ["Crafted by Me"]
title = "Leetcode 59: Spiral Matrix II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 59: Spiral Matrix II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mtx(n, vector<int>(n, 0));
        int cBgn = 0, cEnd = n - 1, rBgn = 0, rEnd = n - 1;
        
        int num = 1;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                mtx[rBgn][i] = num++;
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                mtx[i][cEnd] = num++;
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                mtx[rEnd][i] = num++;
            rEnd--;
            if(cBgn <= cEnd)
            for(int i = rEnd; i >= rBgn; i--)
                mtx[i][cBgn] = num++;
            cBgn++;            
        }
        return mtx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/59.md" >}}
---
{{< youtube RvLrWFBJ9fM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #60: Permutation Sequence](https://grid47.xyz/posts/leetcode_60) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

