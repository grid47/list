
+++
authors = ["Crafted by Me"]
title = "Leetcode 2875: Minimum Size Subarray in Infinite Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2875: Minimum Size Subarray in Infinite Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube nsgqVWeUI24 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2876: Count Visited Nodes in a Directed Graph](https://grid47.xyz/posts/leetcode_2876) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

