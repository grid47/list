
+++
authors = ["Crafted by Me"]
title = "Leetcode 596: Classes More Than 5 Students"
date = "2023-03-17"
description = "Solution to Leetcode 596"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/classes-more-than-5-students/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT class
FROM
        (SELECT class, COUNT(DISTINCT student) AS num 
        FROM Courses
        GROUP BY class) AS TEMP
WHERE num >= 5;
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/596.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

