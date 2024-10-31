
+++
authors = ["Crafted by Me"]
title = "Leetcode 1050: Actors and Directors Who Cooperated At Least Three Times"
date = "2021-12-17"
description = "Solution to Leetcode 1050"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECt actor_id, director_id FROM ActorDirector GROUP BY actor_id, director_id HAVING COUNT(timestamp) >= 3;
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

