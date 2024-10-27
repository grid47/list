
+++
authors = ["Yasir"]
title = "Leetcode 1757: Recyclable and Low Fat Products"
date = "2020-01-06"
description = "Solution to Leetcode 1757"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/recyclable-and-low-fat-products/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT product_id FROM Products WHERE low_fats="Y" AND recyclable="Y";
{{< /highlight >}}

