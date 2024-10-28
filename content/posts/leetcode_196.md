
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 196: Delete Duplicate Emails"
date = "2024-04-16"
description = "Solution to Leetcode 196"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-duplicate-emails/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND
p1.Id > p2.Id
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

