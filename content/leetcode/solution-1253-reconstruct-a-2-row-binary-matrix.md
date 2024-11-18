
+++
authors = ["grid47"]
title = "Leetcode 1253: Reconstruct a 2-Row Binary Matrix"
date = "2024-07-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1253: Reconstruct a 2-Row Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cs) {
        vector<vector<int>> res(2, vector<int>(cs.size()));
        for(int i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i], i++) {
            res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
            res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
        }
        return u == 0 && l == 0 ? res : vector<vector<int>>();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1253.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1254: Number of Closed Islands](https://grid47.xyz/leetcode/solution-1254-number-of-closed-islands/) |
| --- |
