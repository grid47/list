
+++
authors = ["Crafted by Me"]
title = "Leetcode 1587: Bank Account Summary II"
date = "2019-06-29"
description = "Solution to Leetcode 1587"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bank-account-summary-ii/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT s.name, SUM(t.amount) balance
FROM Users s
LEFT JOIN Transactions t
ON s.account = t.account
GROUP BY s.account
HAVING balance > 10000;
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

