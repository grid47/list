
+++
authors = ["grid47"]
title = "Leetcode 1143: Longest Common Subsequence"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1143: Longest Common Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-common-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n1 = t1.size(), n2 = t2.size();
        vector<vector<int>> dp(n1 +1, vector<int>(n2+1, 0));
        for(int i = 0; i < n1; i++)
            for(int j = 0; j < n2; j++)
                if(t1[i] == t2[j])
                    dp[i+1][j+1] = dp[i][j] +1;
        else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        
        return dp[n1][n2];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1143.md" >}}
---
{{< youtube MNykgz1_ONQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1144: Decrease Elements To Make Array Zigzag](https://grid47.xyz/posts/leetcode-1144-decrease-elements-to-make-array-zigzag-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
