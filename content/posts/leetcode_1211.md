
+++
authors = ["Yasir"]
title = "Leetcode 1211: Queries Quality and Percentage"
date = "2021-07-06"
description = "Solution to Leetcode 1211"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT 
query_name, 
ROUND(SUM(rating/position)/COUNT(query_name), 2) as quality, 
ROUND(AVG(if (rating<3, 1, 0))*100, 2) as poor_query_percentage
FROM Queries
GROUP BY query_name
HAVING query_name is not null
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

