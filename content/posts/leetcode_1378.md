
+++
authors = ["Crafted by Me"]
title = "Leetcode 1378: Replace Employee ID With The Unique Identifier"
date = "2020-01-24"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT u.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI u
ON u.id = e.id;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

