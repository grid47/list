
+++
authors = ["Crafted by Me"]
title = "Leetcode 2356: Number of Unique Subjects Taught by Each Teacher"
date = "2018-05-22"
description = "In-depth solution and explanation for Leetcode 2356: Number of Unique Subjects Taught by Each Teacher in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt FROM Teacher
GROUP BY teacher_id;
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2357: Make Array Zero by Subtracting Equal Amounts](https://grid47.xyz/posts/leetcode_2357) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

