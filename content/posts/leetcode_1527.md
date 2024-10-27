
+++
authors = ["Yasir"]
title = "Leetcode 1527: Patients With a Condition"
date = "2020-08-23"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT * FROM Patients WHERE REGEXP_LIKE(conditions,'\\bDIAB1');
{{< /highlight >}}

