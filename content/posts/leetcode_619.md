
+++
authors = ["Yasir"]
title = "Leetcode 619: Biggest Single Number"
date = "2023-02-16"
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

{{< highlight html >}}
# Write your MySQL query statement below
select (
    select num 
    from MyNumbers 
    group by num 
    having count(*) = 1 
    order by num desc limit 1
) as num;
{{< /highlight >}}

