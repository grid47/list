
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 279: Perfect Squares"
date = "2024-01-25"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/279.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

