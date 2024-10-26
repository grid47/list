
+++
authors = ["Yasir"]
title = "Leetcode 181: Employees Earning More Than Their Managers"
date = "2024-04-29"
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

