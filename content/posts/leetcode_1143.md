
+++
authors = ["Yasir"]
title = "Leetcode 1143: Longest Common Subsequence"
date = "2021-09-12"
description = "Solution to Leetcode 1143"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-common-subsequence/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

