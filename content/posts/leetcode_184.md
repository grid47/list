
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 184: Department Highest Salary"
date = "2024-04-28"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee, E.salary
FROM
    Department D,
    Employee E
WHERE E.DepartmentId = D.id
    AND (DepartmentId, Salary) IN
    (SELECT DepartmentId, max(Salary) AS MAX FROM Employee GROUP BY DepartmentId);
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

