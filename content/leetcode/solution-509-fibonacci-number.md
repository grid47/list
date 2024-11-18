
+++
authors = ["grid47"]
title = "Leetcode 509: Fibonacci Number"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 509: Fibonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Recursion","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "WPBTYmvcHXs"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp"
+++



[`Problem Link`](https://leetcode.com/problems/fibonacci-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp" 
    alt="A sequence of numbers where each Fibonacci number glows as it is calculated in the sequence."
    caption="Solution to LeetCode 509: Fibonacci Number Problem"
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
    int fib(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
            
        return dp[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/509.md" >}}
---
{{< youtube WPBTYmvcHXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #513: Find Bottom Left Tree Value](https://grid47.xyz/leetcode/solution-513-find-bottom-left-tree-value/) |
| --- |
