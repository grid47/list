
+++
authors = ["Crafted by Me"]
title = "Leetcode 518: Coin Change II"
date = "2023-06-03"
description = "In-depth solution and explanation for Leetcode 518: Coin Change II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #519: Random Flip Matrix](https://grid47.xyz/posts/leetcode_519) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

