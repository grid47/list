
+++
authors = ["grid47"]
title = "Leetcode 518: Coin Change II"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 518: Coin Change II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coin-change-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[5001][301];
    vector<int> nums;
    int dp(int amnt, int idx) {
        if(idx == nums.size()) return amnt == 0;

        if(memo[amnt][idx] != -1) return memo[amnt][idx];
        // cout << amnt << " " << idx << " " << nums[idx]<< "\n";
        int res = dp(amnt, idx + 1);
        
        if(amnt >= nums[idx])
        res += dp(amnt - nums[idx], idx);
        
        return memo[amnt][idx] = res;
    }
    static bool cmp(int a, int b) {
        return b < a;
    }
    int change(int amount, vector<int>& coins) {
        this->nums = coins;
        sort(nums.begin(), nums.end(), cmp);
        memset(memo, -1, sizeof(memo));
        return dp(amount, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/518.md" >}}
---
{{< youtube 3Er7qS7CQUc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #519: Random Flip Matrix](https://grid47.xyz/posts/leetcode-519-random-flip-matrix-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
