
+++
authors = ["Yasir"]
title = "Leetcode 1789: Primary Department for Each Employee"
date = "2019-12-06"
description = "Solution to Leetcode 1789"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/primary-department-for-each-employee/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'
UNION
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(*) = 1
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

