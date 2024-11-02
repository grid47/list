
+++
authors = ["Crafted by Me"]
title = "Leetcode 1068: Product Sales Analysis I"
date = "2021-11-30"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

