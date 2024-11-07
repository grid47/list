
+++
authors = ["Crafted by Me"]
title = "Leetcode 1633: Percentage of Users Attended a Contest"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1633: Percentage of Users Attended a Contest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Database"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/percentage-of-users-attended-a-contest/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT contest_id, IFNULL(ROUND(COUNT(DISTINCT user_id) * 100/(SELECT COUNT(user_id) FROM Users), 2), 0) percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1633.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1637: Widest Vertical Area Between Two Points Containing No Points](https://grid47.xyz/posts/leetcode_1637) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
