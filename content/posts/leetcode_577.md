
+++
authors = ["Yasir"]
title = "Leetcode 577: Employee Bonus"
date = "2023-03-30"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT e.name, b.bonus FROM Employee e
    LEFT JOIN Bonus b ON b.empId = e.empId
    WHERE b.bonus IS NULL OR b.bonus < 1000;
{{< /highlight >}}

