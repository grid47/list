
+++
authors = ["Yasir"]
title = "Leetcode 607: Sales Person"
date = "2023-02-28"
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

{{< highlight html >}}
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

