
+++
authors = ["Crafted by Me"]
title = "Leetcode 583: Delete Operation for Two Strings"
date = "2023-03-30"
description = "In-depth solution and explanation for Leetcode 583: Delete Operation for Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-operation-for-two-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDistance(string word1, string word2) {
        // lcs
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j + 1], dp[i + 1][j]);
        }

        return word1.size() + word2.size() - 2 * dp[m][n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/583.md" >}}
---

| Next : [LeetCode #584: Find Customer Referee](https://grid47.xyz/posts/leetcode_584) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

