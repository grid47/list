
+++
authors = ["Crafted by Me"]
title = "Leetcode 1148: Article Views I"
date = "2021-09-11"
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

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views WHERE viewer_id=author_id ORDER BY id ASC;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

