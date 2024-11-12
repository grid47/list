
+++
authors = ["grid47"]
title = "Leetcode 593: Valid Square"
date = "2024-09-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 593: Valid Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #606: Construct String from Binary Tree](https://grid47.xyz/posts/leetcode-606-construct-string-from-binary-tree-solution/) |
| --- |
