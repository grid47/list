
+++
authors = ["Crafted by Me"]
title = "Leetcode 1965: Employees With Missing Information"
date = "2019-06-17"
description = "In-depth solution and explanation for Leetcode 1965: Employees With Missing Information in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employees-with-missing-information/description/)

---

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


---


| Next : [LeetCode #1966: Binary Searchable Numbers in an Unsorted Array](grid47.xyz/leetcode_1966) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

