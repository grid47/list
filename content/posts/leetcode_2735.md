
+++
authors = ["Yasir"]
title = "Leetcode 2735: Collecting Chocolates"
date = "2017-05-03"
description = "Solution to Leetcode 2735"
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

{{< highlight html >}}
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

