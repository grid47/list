
+++
authors = ["Crafted by Me"]
title = "Leetcode 577: Employee Bonus"
date = "2023-04-05"
description = "In-depth solution and explanation for Leetcode 577: Employee Bonus in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employee-bonus/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT e.name, b.bonus FROM Employee e
    LEFT JOIN Bonus b ON b.empId = e.empId
    WHERE b.bonus IS NULL OR b.bonus < 1000;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/577.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

