
+++
authors = ["Yasir"]
title = "Leetcode 620: Not Boring Movies"
date = "2023-02-16"
description = "Solution to Leetcode 620"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/not-boring-movies/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
select * from Cinema c where MOD(c.id, 2) = 1 and c.description != "boring" order by c.rating desc
{{< /highlight >}}

