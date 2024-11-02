
+++
authors = ["Crafted by Me"]
title = "Leetcode 183: Customers Who Never Order"
date = "2023-05-03"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/183.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

