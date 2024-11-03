
+++
authors = ["Crafted by Me"]
title = "Leetcode 1789: Primary Department for Each Employee"
date = "2019-12-10"
description = "In-depth solution and explanation for Leetcode 1789: Primary Department for Each Employee in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


| Next : [LeetCode #1790: Check if One String Swap Can Make Strings Equal](grid47.xyz/leetcode_1790) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

