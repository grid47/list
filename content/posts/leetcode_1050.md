
+++
authors = ["Crafted by Me"]
title = "Leetcode 1050: Actors and Directors Who Cooperated At Least Three Times"
date = "2020-12-17"
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

