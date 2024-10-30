
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2875: Minimum Size Subarray in Infinite Array"
date = "2016-12-17"
description = "Solution to Leetcode 2875"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSizeSubarray(vector<int>& A, int target) {
        long sumA = accumulate(A.begin(), A.end(), 0L), su = 0;
        int n = A.size(), k = target / sumA, res = n;
        target %= sumA;
        if (target == 0)
            return k * n;
        unordered_map<long, int> dp{{0L, -1}};
        for (int i = 0; i < 2 * n; ++i) {
            su += A[i % n];
            if (dp.count(su - target))
                res = min(res, i - dp[su - target]);
            dp[su] = i;
        }
        return res < n ? res + k * n : -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

