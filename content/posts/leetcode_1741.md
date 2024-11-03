
+++
authors = ["Crafted by Me"]
title = "Leetcode 1741: Find Total Time Spent by Each Employee"
date = "2020-01-27"
description = "In-depth solution and explanation for Leetcode 1741: Find Total Time Spent by Each Employee in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT
    event_day AS day,
    emp_id,
    SUM(out_time  - in_time) AS total_time
FROM Employees
GROUP BY day, emp_id;
{{< /highlight >}}


---


| Next : [LeetCode #1742: Maximum Number of Balls in a Box](grid47.xyz/leetcode_1742) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

