
+++
authors = ["Crafted by Me"]
title = "Leetcode 1667: Fix Names in a Table"
date = "2020-04-10"
description = "In-depth solution and explanation for Leetcode 1667: Fix Names in a Table in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


"| 1668: Maximum Repeating Substring |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

