
+++
authors = ["Crafted by Me"]
title = "Leetcode 1211: Queries Quality and Percentage"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1211: Queries Quality and Percentage in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queries-quality-and-percentage/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT 
query_name, 
ROUND(SUM(rating/position)/COUNT(query_name), 2) as quality, 
ROUND(AVG(if (rating<3, 1, 0))*100, 2) as poor_query_percentage
FROM Queries
GROUP BY query_name
HAVING query_name is not null
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1211.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1212: Team Scores in Football Tournament](https://grid47.xyz/posts/leetcode_1212) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

