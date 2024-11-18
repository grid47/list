
+++
authors = ["grid47"]
title = "Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "gFsI5OR-GfQ"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/)

---
**Code:**

{{< highlight cpp >}}
int dp[1001][1001] = {};
int mod = 1000000007;
class Solution {
public:
    int numberOfWays(int start, int end, int k) {
        return dfs(k, abs(start - end));
    }
    
    int dfs(int k, int d) {
        if (d >= k) return d == k;
        if(dp[k][d] == 0)
            dp[k][d] = (1 + dfs(k-1, d + 1) + dfs(k -1, abs(d -1))) % mod;
        
        return dp[k][d] -1;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2400.md" >}}
---
{{< youtube gFsI5OR-GfQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2401: Longest Nice Subarray](https://grid47.xyz/leetcode/solution-2401-longest-nice-subarray/) |
| --- |
