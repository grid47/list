
+++
authors = ["Crafted by Me"]
title = "Leetcode 176: Second Highest Salary"
date = "2024-05-09"
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

