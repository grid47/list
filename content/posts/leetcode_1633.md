
+++
authors = ["Crafted by Me"]
title = "Leetcode 1633: Percentage of Users Attended a Contest"
date = "2020-05-14"
description = "In-depth solution and explanation for Leetcode 1633: Percentage of Users Attended a Contest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

