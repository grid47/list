
+++
authors = ["Yasir"]
title = "Leetcode 583: Delete Operation for Two Strings"
date = "2023-03-24"
description = "Solution to Leetcode 583"
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

{{< highlight html >}}
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

