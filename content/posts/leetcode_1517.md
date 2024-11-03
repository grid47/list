
+++
authors = ["Crafted by Me"]
title = "Leetcode 1517: Find Users With Valid E-Mails"
date = "2020-09-07"
description = "In-depth solution and explanation for Leetcode 1517: Find Users With Valid E-Mails in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-users-with-valid-e-mails/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT *
FROM Users
WHERE REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9\.\_\-]*@leetcode[.]com$');
{{< /highlight >}}


---


"| 1518: Water Bottles |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

