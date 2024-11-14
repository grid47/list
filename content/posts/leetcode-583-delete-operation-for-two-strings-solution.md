
+++
authors = ["grid47"]
title = "Leetcode 583: Delete Operation for Two Strings"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 583: Delete Operation for Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-operation-for-two-strings/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/583.webp" 
    alt="Two strings where characters are deleted, with each deletion softly glowing as it happens."
    caption="Solution to LeetCode 583: Delete Operation for Two Strings Problem"
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
{{< youtube tpALbrFWg5U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #589: N-ary Tree Preorder Traversal](https://grid47.xyz/posts/leetcode-589-n-ary-tree-preorder-traversal-solution/) |
| --- |
