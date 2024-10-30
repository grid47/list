
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1729: Find Followers Count"
date = "2020-02-06"
description = "Solution to Leetcode 1729"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-followers-count/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT user_id, COUNT(DISTINCT follower_id) followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

