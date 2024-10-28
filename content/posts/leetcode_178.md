
+++
authors = ["Yasir"]
title = "Leetcode 178: Rank Scores"
date = "2024-05-04"
description = "Solution to Leetcode 178"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rank-scores/description/)

---

**Code:**

{{< highlight html >}}
SELECT
  Score,
  (SELECT count(distinct Score) FROM Scores WHERE Score >= s.Score) `Rank`
FROM Scores s
ORDER BY Score desc;
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

