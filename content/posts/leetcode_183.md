
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 183: Customers Who Never Order"
date = "2024-05-01"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
select A.name AS Customers from Customers A WHERE A.id NOT IN (SELECT B.customerId FROM Orders B);
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/183.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

