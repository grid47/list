
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1587: Bank Account Summary II"
date = "2020-06-25"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

