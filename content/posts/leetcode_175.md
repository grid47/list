
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 175: Combine Two Tables"
date = "2024-05-09"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT Person.firstName,Person.lastName,Address.city,Address.state FROM Person LEFT JOIN Address ON Person.personId = Address.personId
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/175.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

