
+++
authors = ["grid47"]
title = "Leetcode 861: Score After Flipping Matrix"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 861: Score After Flipping Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-after-flipping-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = (1 << n - 1) * m;

        for(int j = 1; j < n; j++) {
            int cur = 0;
            for(int i = 0; i < m; i++)
                cur += grid[i][0] == grid[i][j];
            res += max(cur, m - cur) * (1<<n-j-1);
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/861.md" >}}
---
{{< youtube FbhzRA5den8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #863: All Nodes Distance K in Binary Tree](https://grid47.xyz/posts/leetcode-863-all-nodes-distance-k-in-binary-tree-solution/) |
| --- |
