
+++
authors = ["Crafted by Me"]
title = "Leetcode 861: Score After Flipping Matrix"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 861: Score After Flipping Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Greedy","Matrix"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #862: Shortest Subarray with Sum at Least K](https://grid47.xyz/posts/leetcode_862) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

