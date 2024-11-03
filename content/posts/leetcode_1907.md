
+++
authors = ["Crafted by Me"]
title = "Leetcode 1907: Count Salary Categories"
date = "2019-08-14"
description = "In-depth solution and explanation for Leetcode 1907: Count Salary Categories in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


"| 1908: Game of Nim |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

