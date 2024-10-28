
+++
authors = ["Yasir"]
title = "Leetcode 175: Combine Two Tables"
date = "2024-05-07"
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

