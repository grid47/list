
+++
authors = ["Crafted by Me"]
title = "Leetcode 610: Triangle Judgement"
date = "2022-03-02"
description = "Solution to Leetcode 610"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/triangle-judgement/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT x, y, z,IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle FROM Triangle;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/610.md" >}}
---
{{< youtube QWyzkiwBhFc >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

