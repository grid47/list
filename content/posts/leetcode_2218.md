
+++
authors = ["Crafted by Me"]
title = "Leetcode 2218: Maximum Value of K Coins From Piles"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2218: Maximum Value of K Coins From Piles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/)

---

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


---
{{< youtube 9rRrRXwW0U0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2219: Maximum Sum Score of Array](https://grid47.xyz/posts/leetcode_2219) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
