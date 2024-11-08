
+++
authors = ["grid47"]
title = "Leetcode 322: Coin Change"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 322: Coin Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coin-change/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/322.md" >}}
---
{{< youtube xxrv-uJdV8Y >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #324: Wiggle Sort II](https://grid47.xyz/posts/leetcode_324) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
