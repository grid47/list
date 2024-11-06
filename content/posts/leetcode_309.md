
+++
authors = ["Crafted by Me"]
title = "Leetcode 309: Best Time to Buy and Sell Stock with Cooldown"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 309: Best Time to Buy and Sell Stock with Cooldown in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[5001][2][2];
    vector<int> nums;
    int dp(int idx, bool buy, bool cool) {
        if(idx == nums.size()) return 0;
        
        if(memo[idx][buy][cool] != -1) return memo[idx][buy][cool];
        
        int res = dp(idx + 1, buy, false);
        if(buy && !cool) {
            res = max(res, dp(idx + 1, false, false) - nums[idx]);
        } else if(!buy) {
            res = max(res, dp(idx + 1, true, true) + nums[idx]);
        }
        return memo[idx][buy][cool] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        this->nums = prices;
        return dp(0, true, false);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/309.md" >}}
---
{{< youtube t2Tw5kVkmEY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #310: Minimum Height Trees](https://grid47.xyz/posts/leetcode_310) |
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
