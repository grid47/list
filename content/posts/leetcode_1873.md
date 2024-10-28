
+++
authors = ["Yasir"]
title = "Leetcode 1873: Calculate Special Bonus"
date = "2019-09-13"
description = "Solution to Leetcode 1873"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-special-bonus/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE 'M%') AS bonus FROM Employees ORDER BY employee_id;
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

