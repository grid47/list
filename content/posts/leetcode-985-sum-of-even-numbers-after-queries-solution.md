
+++
authors = ["grid47"]
title = "Leetcode 985: Sum of Even Numbers After Queries"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 985: Sum of Even Numbers After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& qs) {
        vector<int> res = {};
        int sum = accumulate(begin(A), end(A), 0, [](int s, int a) {
            return s + (a % 2 == 0? a : 0);
        });
        for(auto &q: qs) {
            if(A[q[1]] %2 == 0) sum-=A[q[1]];
            A[q[1]] += q[0];
            if(A[q[1]]%2 == 0) sum+=A[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/985.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #988: Smallest String Starting From Leaf](https://grid47.xyz/posts/leetcode-988-smallest-string-starting-from-leaf-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
