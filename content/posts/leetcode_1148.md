
+++
authors = ["Yasir"]
title = "Leetcode 1148: Article Views I"
date = "2021-09-06"
description = "Solution to Leetcode 1148"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/article-views-i/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views WHERE viewer_id=author_id ORDER BY id ASC;
{{< /highlight >}}

