
+++
authors = ["Crafted by Me"]
title = "Leetcode 620: Not Boring Movies"
date = "2022-02-20"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
select * from Cinema c where MOD(c.id, 2) = 1 and c.description != "boring" order by c.rating desc
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/620.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

