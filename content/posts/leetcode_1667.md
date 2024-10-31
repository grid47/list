
+++
authors = ["Crafted by Me"]
title = "Leetcode 1667: Fix Names in a Table"
date = "2020-04-09"
description = "Solution to Leetcode 1667"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fix-names-in-a-table/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT Users.user_id, CONCAT(UPPER(SUBSTR(Users.name, 1, 1)), LOWER(SUBSTR(Users.name, 2))) AS name FROM Users ORDER BY Users.user_id ASC;
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

