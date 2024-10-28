
+++
authors = ["Yasir"]
title = "Leetcode 177: Nth Highest Salary"
date = "2024-05-05"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

