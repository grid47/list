
+++
authors = ["Yasir"]
title = "Leetcode 279: Perfect Squares"
date = "2024-01-23"
description = "Solution to Leetcode 279"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/perfect-squares/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSquares(int n) {
        vector<long> cnt(n + 1, INT_MAX);

        cnt[0] = 0;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j * j <= i; j++)
            cnt[i] = min(cnt[i], cnt[i - j * j] + 1);

        return cnt[n];

    }
};
{{< /highlight >}}

