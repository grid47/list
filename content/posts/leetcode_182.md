
+++
authors = ["Yasir"]
title = "Leetcode 182: Duplicate Emails"
date = "2024-04-29"
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

