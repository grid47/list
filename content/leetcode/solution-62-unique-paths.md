
+++
authors = ["grid47"]
title = "Leetcode 62: Unique Paths"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 62: Unique Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-paths/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/62.webp" 
    alt="A gentle, glowing path winding through a serene landscape, showing multiple routes."
    caption="Solution to LeetCode 62: Unique Paths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        
        return dp[m - 1][n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/62.md" >}}
---
{{< youtube 3ZFvBlynmls >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #63: Unique Paths II](https://grid47.xyz/leetcode/solution-63-unique-paths-ii/) |
| --- |
