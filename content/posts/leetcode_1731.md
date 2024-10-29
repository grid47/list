
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1731: The Number of Employees Which Report to Each Employee"
date = "2020-02-03"
description = "Solution to Leetcode 1731"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT e1.employee_id, e1.name, COUNT(e2.reports_to) reports_count, ROUND(AVG(e2.age)) average_age
FROM Employees e1
INNER JOIN Employees e2
ON e2.reports_to = e1.employee_id
GROUP BY e1.employee_id
ORDER BY e1.employee_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

