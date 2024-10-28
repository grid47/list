
+++
authors = ["Yasir"]
title = "Leetcode 182: Duplicate Emails"
date = "2024-04-30"
description = "Solution to Leetcode 182"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/duplicate-emails/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
select email from person group by email having count(*) > 1;
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

