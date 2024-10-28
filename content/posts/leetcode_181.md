
+++
authors = ["Yasir"]
title = "Leetcode 181: Employees Earning More Than Their Managers"
date = "2024-05-01"
description = "Solution to Leetcode 181"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employees-earning-more-than-their-managers/description/)

---

**Code:**

{{< highlight html >}}
SELECT e2.name as Employee
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerID
WHERE e1.salary < e2.salary
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

