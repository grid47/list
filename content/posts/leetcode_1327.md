
+++
authors = ["Crafted by Me"]
title = "Leetcode 1327: List the Products Ordered in a Period"
date = "2021-03-16"
description = "In-depth solution and explanation for Leetcode 1327: List the Products Ordered in a Period in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/list-the-products-ordered-in-a-period/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
FROM Products p
LEFT JOIN Orders o
ON p.product_id = o.product_id AND Left(o.order_date, 7) = '2020-02'
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1327.md" >}}
---

| Next : [LeetCode #1328: Break a Palindrome](https://grid47.xyz/posts/leetcode_1328) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

