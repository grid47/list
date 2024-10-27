
+++
authors = ["Yasir"]
title = "Leetcode 1633: Percentage of Users Attended a Contest"
date = "2020-05-09"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT contest_id, IFNULL(ROUND(COUNT(DISTINCT user_id) * 100/(SELECT COUNT(user_id) FROM Users), 2), 0) percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
{{< /highlight >}}

