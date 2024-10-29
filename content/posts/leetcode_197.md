
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 197: Rising Temperature"
date = "2024-04-16"
description = "Solution to Leetcode 197"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rising-temperature/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1, Weather AS w2
WHERE w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/197.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

