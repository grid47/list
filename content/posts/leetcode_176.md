
+++
authors = ["Crafted by Me"]
title = "Leetcode 176: Second Highest Salary"
date = "2024-05-10"
description = "In-depth solution and explanation for Leetcode 176: Second Highest Salary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #177: Nth Highest Salary](https://grid47.xyz/posts/leetcode_177) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

