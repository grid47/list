
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1789: Primary Department for Each Employee"
date = "2019-12-08"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

