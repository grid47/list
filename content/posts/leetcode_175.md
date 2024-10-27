
+++
authors = ["Yasir"]
title = "Leetcode 175: Combine Two Tables"
date = "2024-05-06"
description = "Solution to Leetcode 175"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combine-two-tables/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT Person.firstName,Person.lastName,Address.city,Address.state FROM Person LEFT JOIN Address ON Person.personId = Address.personId
{{< /highlight >}}

