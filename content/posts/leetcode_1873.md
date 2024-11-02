
+++
authors = ["Crafted by Me"]
title = "Leetcode 1873: Calculate Special Bonus"
date = "2019-09-17"
description = "Solution to Leetcode 1873"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-special-bonus/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE 'M%') AS bonus FROM Employees ORDER BY employee_id;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

