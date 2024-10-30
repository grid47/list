
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1661: Average Time of Process per Machine"
date = "2020-04-14"
description = "Solution to Leetcode 1661"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-time-of-process-per-machine/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a1.timestamp - a2.timestamp), 3) processing_time
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id AND a1.activity_type = 'end' AND a2.activity_type = 'start'
GROUP BY machine_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

