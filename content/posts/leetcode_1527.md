
+++
authors = ["Crafted by Me"]
title = "Leetcode 1527: Patients With a Condition"
date = "2020-08-28"
description = "Solution to Leetcode 1527"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/patients-with-a-condition/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT * FROM Patients WHERE REGEXP_LIKE(conditions,'\\bDIAB1');
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

