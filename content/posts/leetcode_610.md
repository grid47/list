
+++
authors = ["Yasir"]
title = "Leetcode 610: Triangle Judgement"
date = "2023-02-26"
description = "Solution to Leetcode 610"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/triangle-judgement/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT x, y, z,IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle FROM Triangle;
{{< /highlight >}}

