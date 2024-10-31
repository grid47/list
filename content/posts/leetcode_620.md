
+++
authors = ["Crafted by Me"]
title = "Leetcode 620: Not Boring Movies"
date = "2023-02-20"
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

