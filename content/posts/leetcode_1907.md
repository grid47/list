
+++
authors = ["Crafted by Me"]
title = "Leetcode 1907: Count Salary Categories"
date = "2019-08-13"
description = "Solution to Leetcode 1907"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-salary-categories/description/)

---

**Code:**

{{< highlight cpp >}}
SELECT 'Low Salary' AS category, (SUM(income < 20000)) AS accounts_count FROM Accounts
UNION
SELECT 'Average Salary', SUM(income >= 20000 AND income <= 50000) FROM Accounts
UNION
SELECT 'High Salary', SUM(income > 50000) FROM Accounts;
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

