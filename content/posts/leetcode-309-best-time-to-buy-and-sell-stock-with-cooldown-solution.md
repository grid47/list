
+++
authors = ["grid47"]
title = "Leetcode 309: Best Time to Buy and Sell Stock with Cooldown"
date = "2024-10-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 309: Best Time to Buy and Sell Stock with Cooldown in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/309.webp" 
    alt="A graph of stock prices where the optimal buying and selling points are gently illuminated, with cooldown periods clearly marked"
    caption="Solution to LeetCode 309: Best Time to Buy and Sell Stock with Cooldown Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #310: Minimum Height Trees](https://grid47.xyz/posts/leetcode-310-minimum-height-trees-solution/) |
| --- |
