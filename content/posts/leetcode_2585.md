
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2585: Number of Ways to Earn Points"
date = "2017-10-02"
description = "Solution to Leetcode 2585"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-earn-points/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int n;
    vector<vector<int>> types, memo;
    
    int dp(int idx, int hit) {
        if(idx == n) return hit == 0? 1: 0;
        if(hit == 0) return 1;
        if(memo[idx][hit] != -1) return memo[idx][hit];
        long ans = 0;
        for(int i = 0; i <= types[idx][0]; i++) {
            if(hit >= types[idx][1] * i) {
                ans = (ans + dp(idx + 1, hit - types[idx][1] * i)) % mod;
            }
        }
        return memo[idx][hit] = ans;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n = types.size();
        memo.resize(51, vector<int>(1001, -1));
        this->types = types;
        return dp(0, target);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
