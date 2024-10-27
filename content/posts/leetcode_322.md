
+++
authors = ["Yasir"]
title = "Leetcode 322: Coin Change"
date = "2023-12-11"
description = "Solution to Leetcode 322"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coin-change/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> coin;
    vector<vector<int>> memo;
    static bool cmp(int a, int b) {
        return a > b;
    }
    
    int dp(int idx, int amnt) {
        if(idx == coin.size()) return amnt == 0? 0: INT_MAX-1;
        
        if(memo[idx][amnt] != -1) return memo[idx][amnt];
        
        int res;
        if(amnt >= coin[idx]) {
            int r1 = 1 + dp(idx, amnt - coin[idx]);            
            int r2 = dp(idx + 1, amnt);
            res = min(r1, r2);
        } else {
            res = dp(idx + 1, amnt);
        }

        return memo[idx][amnt] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), cmp);
        
        this->coin = coins;
        
        memo.resize(coin.size(),vector<int>(amount + 1, -1) );
        int ans = dp(0, amount);
        return ans == INT_MAX-1?-1: ans;
    }
};
{{< /highlight >}}

