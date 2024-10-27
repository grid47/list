
+++
authors = ["Yasir"]
title = "Leetcode 1280: Students and Examinations"
date = "2021-04-27"
description = "Solution to Leetcode 1280"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/students-and-examinations/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.student_id) AS attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;
{{< /highlight >}}

