
+++
authors = ["grid47"]
title = "Leetcode 2875: Minimum Size Subarray in Infinite Array"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2875: Minimum Size Subarray in Infinite Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2875.md" >}}
---
{{< youtube nsgqVWeUI24 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2894: Divisible and Non-divisible Sums Difference](https://grid47.xyz/posts/leetcode-2894-divisible-and-non-divisible-sums-difference-solution/) |
| --- |
