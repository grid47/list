
+++
authors = ["Yasir"]
title = "Leetcode 586: Customer Placing the Largest Number of Orders"
date = "2023-03-21"
description = "Solution to Leetcode 586"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*)
DESC LIMIT 1;
{{< /highlight >}}

