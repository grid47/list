
+++
authors = ["grid47"]
title = "Leetcode 2319: Check if Matrix Is X-Matrix"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2319: Check if Matrix Is X-Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& g) {
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j) {
            if (i == j || i + j == g.size() - 1) {
                if (g[i][j] == 0)
                    return false;
            }
            else if (g[i][j] > 0)
                return false;
        }
    return true;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2319.md" >}}
---
{{< youtube l7O_4za547A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2320: Count Number of Ways to Place Houses](https://grid47.xyz/leetcode/solution-2320-count-number-of-ways-to-place-houses/) |
| --- |
