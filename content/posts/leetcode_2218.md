
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2218: Maximum Value of K Coins From Piles"
date = "2018-10-05"
description = "Solution to Leetcode 2218"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/)

---
{{< youtube 9rRrRXwW0U0 >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][2001];
    int dp(vector<vector<int>>& piles, int idx, int k) {
        if(k == 0) return 0;
        if(idx == piles.size()) return INT_MIN;
        if(memo[idx][k] != -1) return memo[idx][k];
        int ans = dp(piles, idx + 1, k);
        for(int i = 0; i < piles[idx].size(); i++) {
            if(i < k)
            ans = max(ans, piles[idx][i] + dp(piles, idx + 1, k - (i + 1)) );
        }
        return memo[idx][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        for(int i = 0; i < piles.size(); i++)
        partial_sum(piles[i].begin(), piles[i].end(), piles[i].begin());
        
        
        memset(memo, -1, sizeof(memo));
        return dp(piles, 0, k);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

