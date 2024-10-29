
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 586: Customer Placing the Largest Number of Orders"
date = "2023-03-24"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*)
DESC LIMIT 1;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/586.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

