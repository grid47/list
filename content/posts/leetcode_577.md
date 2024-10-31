
+++
authors = ["Crafted by Me"]
title = "Leetcode 577: Employee Bonus"
date = "2023-04-04"
description = "Solution to Leetcode 577"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employee-bonus/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT e.name, b.bonus FROM Employee e
    LEFT JOIN Bonus b ON b.empId = e.empId
    WHERE b.bonus IS NULL OR b.bonus < 1000;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/577.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

