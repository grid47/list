
+++
authors = ["Yasir"]
title = "Leetcode 196: Delete Duplicate Emails"
date = "2024-04-15"
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

{{< highlight html >}}
# Write your MySQL query statement below
DELETE p1
FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND
p1.Id > p2.Id
{{< /highlight >}}

