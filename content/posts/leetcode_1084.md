
+++
authors = ["Yasir"]
title = "Leetcode 1084: Sales Analysis III"
date = "2021-11-10"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT p.product_id, product_name 
FROM Product p 
LEFT JOIN Sales s
ON s.product_id = p.product_id
GROUP BY p.product_id
HAVING MIN(sale_date) >= CAST('2019-01-01' AS DATE) AND
       MAX(sale_date) <= CAST('2019-03-31' AS DATE);
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

