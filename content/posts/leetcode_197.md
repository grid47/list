
+++
authors = ["Crafted by Me"]
title = "Leetcode 197: Rising Temperature"
date = "2024-04-19"
description = "In-depth solution and explanation for Leetcode 197: Rising Temperature in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rising-temperature/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1, Weather AS w2
WHERE w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/197.md" >}}
---
{{< youtube FROOb0_r1xQ >}}
| Next : [LeetCode #198: House Robber](https://grid47.xyz/posts/leetcode_198) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

