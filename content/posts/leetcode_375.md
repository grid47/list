
+++
authors = ["Crafted by Me"]
title = "Leetcode 375: Guess Number Higher or Lower II"
date = "2023-10-24"
description = "In-depth solution and explanation for Leetcode 375: Guess Number Higher or Lower II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<vector<int>> table;
public:
    int getMoneyAmount(int n) {
        table.resize(n + 1, vector<int>(n + 1));
        return dpf(table, 1, n);
    }

    int dpf(vector<vector<int>> &dp, int s, int e) {
        if(s >= e) return 0;
        if(dp[s][e] > 0) return dp[s][e];
        int res = INT_MAX;
        for(int x = s; x <= e; x++) {
            int tmp = (x + max(dpf(dp, s, x-1), dpf(dp, x + 1, e)));
            res = min(res, tmp);
        }
        return dp[s][e] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/375.md" >}}
---
{{< youtube Gi-FQM3Ez84 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #376: Wiggle Subsequence](https://grid47.xyz/posts/leetcode_376) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

