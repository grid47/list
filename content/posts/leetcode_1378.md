
+++
authors = ["Yasir"]
title = "Leetcode 1378: Replace Employee ID With The Unique Identifier"
date = "2021-01-20"
description = "Solution to Leetcode 1378"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT u.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI u
ON u.id = e.id;
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

