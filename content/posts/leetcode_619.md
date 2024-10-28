
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 619: Biggest Single Number"
date = "2023-02-18"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

