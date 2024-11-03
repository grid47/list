
+++
authors = ["Crafted by Me"]
title = "Leetcode 1105: Filling Bookcase Shelves"
date = "2021-10-24"
description = "In-depth solution and explanation for Leetcode 1105: Filling Bookcase Shelves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/filling-bookcase-shelves/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + books[i][1];
            int sum = 0, height = 0;
            for(int j = i; j >= 0; j--) {
                sum += books[j][0];
                if(sum > shelfWidth) break;
                else {
                    height = max(height, books[j][1]);
                    dp[i + 1] = min(dp[j] + height, dp[i+1]);
                }
            }
        }
        return dp[n];        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1105.md" >}}
---


| Next : [LeetCode #1106: Parsing A Boolean Expression](grid47.xyz/leetcode_1106) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

