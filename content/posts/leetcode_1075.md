
+++
authors = ["Crafted by Me"]
title = "Leetcode 1075: Project Employees I"
date = "2020-11-22"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT p.project_id, ROUND(AVG(e.experience_years), 2) AS average_years 
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

