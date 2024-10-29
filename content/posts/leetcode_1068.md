
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1068: Product Sales Analysis I"
date = "2021-11-27"
description = "Solution to Leetcode 1068"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/product-sales-analysis-i/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT a.product_name, b.year, b.price 
FROM Sales b
LEFT JOIN Product a
ON a.product_id = b.product_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

