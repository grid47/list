
+++
authors = ["Yasir"]
title = "Leetcode 1105: Filling Bookcase Shelves"
date = "2021-10-20"
description = "Solution to Leetcode 1105"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

