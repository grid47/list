
+++
authors = ["Yasir"]
title = "Leetcode 1068: Product Sales Analysis I"
date = "2021-11-25"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT a.product_name, b.year, b.price 
FROM Sales b
LEFT JOIN Product a
ON a.product_id = b.product_id;
{{< /highlight >}}

