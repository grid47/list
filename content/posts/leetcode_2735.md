
+++
authors = ["Crafted by Me"]
title = "Leetcode 2735: Collecting Chocolates"
date = "2017-05-08"
description = "In-depth solution and explanation for Leetcode 2735: Collecting Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/collecting-chocolates/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minCost(vector<int>& A, int x) {
        int n = A.size();
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] += 1L * i * x;
            int cur = A[i];
            for (int k = 0; k < n; k++) {
                cur = min(cur, A[(i - k + n) % n]);
                res[k] += cur;
            }
        }
        return *std::min_element(res.begin(), res.end());
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2736: Maximum Sum Queries](https://grid47.xyz/posts/leetcode_2736) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

