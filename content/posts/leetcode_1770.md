
+++
authors = ["Crafted by Me"]
title = "Leetcode 1770: Maximum Score from Performing Multiplication Operations"
date = "2019-12-29"
description = "In-depth solution and explanation for Leetcode 1770: Maximum Score from Performing Multiplication Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| Next : [LeetCode #1771: Maximize Palindrome Length From Subsequences](https://grid47.xyz/posts/leetcode_1771) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

