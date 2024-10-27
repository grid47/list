
+++
authors = ["Yasir"]
title = "Leetcode 1378: Replace Employee ID With The Unique Identifier"
date = "2021-01-19"
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

