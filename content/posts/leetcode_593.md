
+++
authors = ["Crafted by Me"]
title = "Leetcode 593: Valid Square"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 593: Valid Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int d(vector<int> p, vector<int> q) {
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
        return !s.count(0) && s.size() == 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/593.md" >}}
---
{{< youtube 5ErP0_vpzvI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #594: Longest Harmonious Subsequence](https://grid47.xyz/posts/leetcode_594) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

