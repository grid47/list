
+++
authors = ["Crafted by Me"]
title = "Leetcode 1587: Bank Account Summary II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1587: Bank Account Summary II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Database"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bank-account-summary-ii/description/)

---
**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT s.name, SUM(t.amount) balance
FROM Users s
LEFT JOIN Transactions t
ON s.account = t.account
GROUP BY s.account
HAVING balance > 10000;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1587.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1589: Maximum Sum Obtained of Any Permutation](https://grid47.xyz/posts/leetcode_1589) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
