
+++
authors = ["Crafted by Me"]
title = "Leetcode 1978: Employees Whose Manager Left the Company"
date = "2019-06-04"
description = "In-depth solution and explanation for Leetcode 1978: Employees Whose Manager Left the Company in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/employees-whose-manager-left-the-company/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE manager_id NOT IN (SELECT employee_id FROM Employees)
AND salary < 30000 ORDER BY employee_id;
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1979: Find Greatest Common Divisor of Array](https://grid47.xyz/posts/leetcode_1979) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

