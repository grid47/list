
+++
authors = ["Yasir"]
title = "Leetcode 584: Find Customer Referee"
date = "2023-03-24"
description = "Solution to Leetcode 584"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-customer-referee/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT name FROM Customer WHERE referee_id IS NULL OR referee_id != 2;
{{< /highlight >}}

