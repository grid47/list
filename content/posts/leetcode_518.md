
+++
authors = ["Yasir"]
title = "Leetcode 518: Coin Change II"
date = "2023-05-29"
description = "Solution to Leetcode 518"
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

{{< highlight html >}}
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

