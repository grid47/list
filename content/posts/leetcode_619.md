
+++
authors = ["Crafted by Me"]
title = "Leetcode 619: Biggest Single Number"
date = "2022-02-21"
description = "Solution to Leetcode 619"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/biggest-single-number/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
select (
    select num 
    from MyNumbers 
    group by num 
    having count(*) = 1 
    order by num desc limit 1
) as num;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/619.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

