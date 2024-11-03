
+++
authors = ["Crafted by Me"]
title = "Leetcode 184: Department Highest Salary"
date = "2024-05-02"
description = "In-depth solution and explanation for Leetcode 184: Department Highest Salary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/department-highest-salary/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee, E.salary
FROM
    Department D,
    Employee E
WHERE E.DepartmentId = D.id
    AND (DepartmentId, Salary) IN
    (SELECT DepartmentId, max(Salary) AS MAX FROM Employee GROUP BY DepartmentId);
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/184.md" >}}
---
{{< youtube LO0a31mkY6Q >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #185: Department Top Three Salaries](https://grid47.xyz/posts/leetcode_185) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

