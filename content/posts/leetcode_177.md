
+++
authors = ["Crafted by Me"]
title = "Leetcode 177: Nth Highest Salary"
date = "2023-05-09"
description = "Solution to Leetcode 177"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/nth-highest-salary/description/)

---

**Code:**

{{< highlight cpp >}}
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT M, 1
  );
END
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/177.md" >}}
---
{{< youtube lMUMS3hKd74 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

