
+++
authors = ["Yasir"]
title = "Leetcode 184: Department Highest Salary"
date = "2024-04-26"
description = "Solution to Leetcode 184"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/department-highest-salary/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee, E.salary
FROM
    Department D,
    Employee E
WHERE E.DepartmentId = D.id
    AND (DepartmentId, Salary) IN
    (SELECT DepartmentId, max(Salary) AS MAX FROM Employee GROUP BY DepartmentId);
{{< /highlight >}}

