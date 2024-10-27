
+++
authors = ["Yasir"]
title = "Leetcode 1683: Invalid Tweets"
date = "2020-03-20"
description = "Solution to Leetcode 1683"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/invalid-tweets/description/)

---

**Code:**

{{< highlight html >}}
# Write your MySQL query statement below
SELECT tweet_id FROM Tweets WHERE LENGTH(content) > 15;
{{< /highlight >}}

