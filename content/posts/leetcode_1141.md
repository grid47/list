
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1141: User Activity for the Past 30 Days I"
date = "2021-09-15"
description = "Solution to Leetcode 1141"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date > "2019-06-27" AND activity_date <= "2019-07-27"
GROUP BY activity_date;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

