
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2356: Number of Unique Subjects Taught by Each Teacher"
date = "2018-05-18"
description = "Solution to Leetcode 2356"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt FROM Teacher
GROUP BY teacher_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

