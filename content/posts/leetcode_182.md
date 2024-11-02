
+++
authors = ["Crafted by Me"]
title = "Leetcode 182: Duplicate Emails"
date = "2023-05-04"
description = "Solution to Leetcode 182"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/duplicate-emails/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
select email from person group by email having count(*) > 1;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/182.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

