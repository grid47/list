
+++
authors = ["Yasir"]
title = "Leetcode 1407: Top Travellers"
date = "2020-12-21"
description = "Solution to Leetcode 1407"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/top-travellers/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT u.name, IFNULL(SUM(r.distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC, name ASC;
{{< /highlight >}}

