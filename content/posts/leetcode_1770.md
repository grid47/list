
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1770: Maximum Score from Performing Multiplication Operations"
date = "2019-12-26"
description = "Solution to Leetcode 1770"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<int> nums, mul;
    vector<vector<int>> mem;
    int maximumScore(vector<int>& nums, vector<int>& mul) {

        this->nums = nums;
        this->mul = mul;
        n = nums.size();
        m = mul.size();

        mem.resize(m + 1, vector<int>((m + 1) + 1000 * (m + 1), -1));

        return dp(0, 0, n - 1);
    }

    int dp(int idx, int l, int r) {
        if(idx == m || l > r) return 0;

        if(mem[idx][(l) + 1000 * (n - r)] != -1) return mem[idx][(l) + 1000 * (n - r)];

        int res = mul[idx] * nums[l] + dp(idx + 1, l + 1, r);
        res = max(res, mul[idx] * nums[r] + dp(idx + 1, l, r - 1));

        return mem[idx][(l) + 1000 * (n - r)] = res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
