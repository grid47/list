
+++
authors = ["grid47"]
title = "Leetcode 1770: Maximum Score from Performing Multiplication Operations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1770: Maximum Score from Performing Multiplication Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1770.md" >}}
---
{{< youtube ilIoqADfcYQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1773: Count Items Matching a Rule](https://grid47.xyz/posts/leetcode-1770-maximum-score-from-performing-multiplication-operations-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
