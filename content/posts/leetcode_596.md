
+++
authors = ["Yasir"]
title = "Leetcode 596: Classes More Than 5 Students"
date = "2023-03-12"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT class
FROM
        (SELECT class, COUNT(DISTINCT student) AS num 
        FROM Courses
        GROUP BY class) AS TEMP
WHERE num >= 5;
{{< /highlight >}}

