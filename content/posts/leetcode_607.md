
+++
authors = ["Crafted by Me"]
title = "Leetcode 607: Sales Person"
date = "2023-03-05"
description = "Solution to Leetcode 607"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sales-person/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT s.name
    FROM SalesPerson s
    WHERE s.name NOT IN(
    SELECT s.name
        FROM SalesPerson s
            LEFT JOIN Orders o ON s.sales_id=o.sales_id
            LEFT JOIN Company c ON c.com_id=o.com_id
        WHERE c.name='RED');
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/607.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

