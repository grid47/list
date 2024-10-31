
+++
authors = ["Crafted by Me"]
title = "Leetcode 1434: Number of Ways to Wear Different Hats to Each Other"
date = "2020-11-28"
description = "Solution to Leetcode 1434"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n, M = 1e9 + 7;
    
    int dfs(vector<vector<int>>& hatsToPeople, vector<vector<int>>& dp, int hat, int mask) {
        if (mask == (1 << n) - 1) return 1;
        if (hat > 40) return 0;
        if (dp[mask][hat] != -1) return dp[mask][hat];
        long res = dfs(hatsToPeople, dp, hat + 1, mask);
        for (auto& person: hatsToPeople[hat]) {
            if ((1 << person) & mask) continue;
            (res += dfs(hatsToPeople, dp, hat + 1, mask | (1 << person))) %= M;
        }
        return dp[mask][hat] = res;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<vector<int>> hatsToPeople(41);
        for (int i = 0; i < n; i++) {
            for (auto &h : hats[i]) {
                hatsToPeople[h].push_back(i);
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(41, -1));
        return dfs(hatsToPeople, dp, 1, 0);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

