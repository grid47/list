
+++
authors = ["grid47"]
title = "Leetcode 2672: Number of Adjacent Elements With the Same Color"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2672: Number of Adjacent Elements With the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    int c[100003] = {}, adj = 0;
    vector<int> res;
    for (const auto &q : queries) {
        int i = q[0] + 1, color_i = q[1];
        if (c[i])
            adj -= (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        c[i] = color_i;
        adj += (c[i - 1] == c[i]) + (c[i + 1] == c[i]);
        res.push_back(adj);
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2672.md" >}}
---
{{< youtube w3L3-aRiNXE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2673: Make Costs of Paths Equal in a Binary Tree](https://grid47.xyz/posts/leetcode-2673-make-costs-of-paths-equal-in-a-binary-tree-solution/) |
| --- |
