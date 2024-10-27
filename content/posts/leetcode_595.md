
+++
authors = ["Yasir"]
title = "Leetcode 595: Big Countries"
date = "2023-03-13"
description = "Solution to Leetcode 595"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/big-countries/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT name, population, area FROM World WHERE area >= 3000000 OR population >= 25000000;
{{< /highlight >}}

