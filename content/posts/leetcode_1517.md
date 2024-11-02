
+++
authors = ["Crafted by Me"]
title = "Leetcode 1517: Find Users With Valid E-Mails"
date = "2019-09-07"
description = "Solution to Leetcode 1517"
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

