
+++
authors = ["Crafted by Me"]
title = "Leetcode 196: Delete Duplicate Emails"
date = "2024-04-20"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/196.md" >}}
- by gpt
        
---
{{< youtube TqjS05MEi1E >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

