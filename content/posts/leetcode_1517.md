
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1517: Find Users With Valid E-Mails"
date = "2020-09-03"
description = "Solution to Leetcode 1517"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-users-with-valid-e-mails/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9\.\_\-]*@leetcode[.]com$');
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

