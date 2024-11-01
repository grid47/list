
+++
authors = ["Crafted by Me"]
title = "Leetcode 181: Employees Earning More Than Their Managers"
date = "2024-05-05"
description = "Solution to Leetcode 181"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employees-earning-more-than-their-managers/description/)

---

**Code:**

{{< highlight cpp >}}
SELECT e2.name as Employee
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerID
WHERE e1.salary < e2.salary
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/181.md" >}}
- by gpt
        
---
{{< youtube wnBab2aFdCc >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

