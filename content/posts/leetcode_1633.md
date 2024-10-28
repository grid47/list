
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1633: Percentage of Users Attended a Contest"
date = "2020-05-10"
description = "Solution to Leetcode 1633"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/percentage-of-users-attended-a-contest/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT contest_id, IFNULL(ROUND(COUNT(DISTINCT user_id) * 100/(SELECT COUNT(user_id) FROM Users), 2), 0) percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

