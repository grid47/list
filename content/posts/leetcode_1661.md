
+++
authors = ["Yasir"]
title = "Leetcode 1661: Average Time of Process per Machine"
date = "2020-04-11"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a1.timestamp - a2.timestamp), 3) processing_time
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id AND a1.activity_type = 'end' AND a2.activity_type = 'start'
GROUP BY machine_id;
{{< /highlight >}}

