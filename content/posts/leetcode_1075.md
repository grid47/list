
+++
authors = ["Yasir"]
title = "Leetcode 1075: Project Employees I"
date = "2021-11-18"
description = "Solution to Leetcode 1075"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/project-employees-i/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years 
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;
{{< /highlight >}}

