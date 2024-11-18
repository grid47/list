
+++
authors = ["grid47"]
title = "Leetcode 375: Guess Number Higher or Lower II"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 375: Guess Number Higher or Lower II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/375.webp" 
    alt="Similar to the previous idea, but with multiple guesses and a progressively smaller range."
    caption="Solution to LeetCode 375: Guess Number Higher or Lower II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #376: Wiggle Subsequence](https://grid47.xyz/leetcode/solution-376-wiggle-subsequence/) |
| --- |
