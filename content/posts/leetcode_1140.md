
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1140: Stone Game II"
date = "2021-09-16"
description = "Solution to Leetcode 1140"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    /*
    
    Taking postfix sum to count pile is new concept - residual count
    
    Thinking like, I had taken this much and pick what you
    require out of remaining, from how much ever you picked
    the rest is mine
    
    each call is others turn
    
    */
    vector<int> piles;
    vector<vector<int>> memo;
    int n;
    int dp(int idx, int m) {
        if(idx + 2* m >= piles.size()) return piles[idx];
        if(memo[idx][m] != -1) return memo[idx][m];
        int ans = 0;
        int tmp = 0;
        for(int x = 1; x <= 2 * m; x++) {
            int tmp = piles[idx] - piles[idx + x];
            ans = max(ans, tmp + piles[idx + x] - dp(idx + x, max(m, x)) );
        }
        return memo[idx][m] = ans;
    }
    int stoneGameII(vector<int>& p) {
        n = p.size();
        piles = p;
        memo.resize(n, vector<int>(n, -1));
        for(int i = p.size() - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
        return dp(0, 1);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
