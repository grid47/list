
+++
authors = ["Crafted by Me"]
title = "Leetcode 1582: Special Positions in a Binary Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1582: Special Positions in a Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) row[i]++, col[j]++;
        }

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1582.md" >}}
---
{{< youtube CsxwXaPmMyE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1583: Count Unhappy Friends](https://grid47.xyz/posts/leetcode_1583) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
