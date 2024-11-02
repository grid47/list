
+++
authors = ["Crafted by Me"]
title = "Leetcode 1084: Sales Analysis III"
date = "2020-11-13"
description = "Solution to Leetcode 1084"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sales-analysis-iii/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT p.product_id, product_name 
FROM Product p 
LEFT JOIN Sales s
ON s.product_id = p.product_id
GROUP BY p.product_id
HAVING MIN(sale_date) >= CAST('2019-01-01' AS DATE) AND
       MAX(sale_date) <= CAST('2019-03-31' AS DATE);
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

