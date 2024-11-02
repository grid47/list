
+++
authors = ["Crafted by Me"]
title = "Leetcode 1251: Average Selling Price"
date = "2020-05-30"
description = "Solution to Leetcode 1251"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-selling-price/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT p.product_id, IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) AS average_price 
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND p.start_date <= u.purchase_date AND u.purchase_date <= p.end_date
GROUP BY p.product_id;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

