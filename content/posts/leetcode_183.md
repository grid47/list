
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 183: Customers Who Never Order"
date = "2024-04-29"
description = "Solution to Leetcode 183"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/customers-who-never-order/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
select A.name AS Customers from Customers A WHERE A.id NOT IN (SELECT B.customerId FROM Orders B);
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

