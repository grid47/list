
+++
authors = ["Yasir"]
title = "Leetcode 1741: Find Total Time Spent by Each Employee"
date = "2020-01-22"
description = "Solution to Leetcode 1741"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-total-time-spent-by-each-employee/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT
    event_day AS day,
    emp_id,
    SUM(out_time  - in_time) AS total_time
FROM Employees
GROUP BY day, emp_id;
{{< /highlight >}}

