
+++
authors = ["Yasir"]
title = "Leetcode 375: Guess Number Higher or Lower II"
date = "2023-10-19"
description = "Solution to Leetcode 375"
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

{{< highlight html >}}
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

