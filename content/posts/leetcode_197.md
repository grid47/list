
+++
authors = ["Yasir"]
title = "Leetcode 197: Rising Temperature"
date = "2024-04-14"
description = "Solution to Leetcode 197"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rising-temperature/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1, Weather AS w2
WHERE w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;
{{< /highlight >}}

