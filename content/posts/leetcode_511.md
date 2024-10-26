
+++
authors = ["Yasir"]
title = "Leetcode 511: Game Play Analysis I"
date = "2023-06-04"
description = "Solution to Leetcode 511"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/game-play-analysis-i/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
{{< /highlight >}}

