
+++
authors = ["grid47"]
title = "Leetcode 322: Coin Change"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 322: Coin Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coin-change/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/322.webp" 
    alt="A set of coins gradually transforming into the fewest possible number of coins needed to make the change, glowing softly."
    caption="Solution to LeetCode 322: Coin Change Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #324: Wiggle Sort II](https://grid47.xyz/posts/leetcode-324-wiggle-sort-ii-solution/) |
| --- |
