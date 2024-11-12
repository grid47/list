
+++
authors = ["grid47"]
title = "Leetcode 1049: Last Stone Weight II"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1049: Last Stone Weight II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-stone-weight-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;
        for(int x: stones) sum += x;

        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

        for (int i = 1; i < n + 1  ; i++)
        for (int j = 0; j < sum / 2 + 1; j++) {
            if(j >= stones[i - 1]) 
                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            else dp[i][j] = dp[i - 1][j];
        }

        return sum - 2 * dp[n][sum / 2];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1049.md" >}}
---
{{< youtube gdXkkmzvR3c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1051: Height Checker](https://grid47.xyz/posts/leetcode-1051-height-checker-solution/) |
| --- |
