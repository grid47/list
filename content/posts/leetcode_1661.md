
+++
authors = ["Crafted by Me"]
title = "Leetcode 1661: Average Time of Process per Machine"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1661: Average Time of Process per Machine in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Database"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-time-of-process-per-machine/description/)

---
**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a1.timestamp - a2.timestamp), 3) processing_time
FROM Activity a1
JOIN Activity a2
ON a1.machine_id = a2.machine_id AND a1.activity_type = 'end' AND a2.activity_type = 'start'
GROUP BY machine_id;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1661.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1662: Check If Two String Arrays are Equivalent](https://grid47.xyz/posts/leetcode_1662) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
