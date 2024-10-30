
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1327: List the Products Ordered in a Period"
date = "2021-03-14"
description = "Solution to Leetcode 1327"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/list-the-products-ordered-in-a-period/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

