
+++
authors = ["Crafted by Me"]
title = "Leetcode 176: Second Highest Salary"
date = "2023-05-10"
description = "Solution to Leetcode 176"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/second-highest-salary/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT MAX(Salary) AS "SecondHighestSalary" FROM Employee WHERE Salary < (SELECT MAX(Salary) FROM Employee);
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/176.md" >}}
---
{{< youtube 3xc0_XIob1M >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

