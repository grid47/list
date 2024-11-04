
+++
authors = ["Crafted by Me"]
title = "Leetcode 1795: Rearrange Products Table"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1795: Rearrange Products Table in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-products-table/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT product_id, 'store1' AS store, store1 AS price FROM Products
WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2', store2 AS price FROM Products
WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3', store3 AS price FROM Products
WHERE store3 IS NOT NULL;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1795.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1796: Second Largest Digit in a String](https://grid47.xyz/posts/leetcode_1796) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

