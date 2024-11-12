
+++
authors = ["grid47"]
title = "Leetcode 1672: Richest Customer Wealth"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1672: Richest Customer Wealth in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/richest-customer-wealth/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for (auto &customer : accounts)
            richest = max (richest, accumulate(customer.begin(), customer.end(), 0));
        
        return richest;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1672.md" >}}
---
{{< youtube Aap1zzi70Pg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1673: Find the Most Competitive Subsequence](https://grid47.xyz/posts/leetcode-1673-find-the-most-competitive-subsequence-solution/) |
| --- |
