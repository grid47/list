
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1965: Employees With Missing Information"
date = "2019-06-15"
description = "Solution to Leetcode 1965"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employees-with-missing-information/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT T.employee_id
FROM
    (SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
    UNION
     SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id))
AS T
WHERE T.salary IS NULL OR T.name IS NULL
ORDER BY employee_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

