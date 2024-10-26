
+++
authors = ["Yasir"]
title = "Leetcode 183: Customers Who Never Order"
date = "2024-04-27"
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

{{< highlight html >}}
# Write your MySQL query statement below
select A.name AS Customers from Customers A WHERE A.id NOT IN (SELECT B.customerId FROM Orders B);
{{< /highlight >}}

