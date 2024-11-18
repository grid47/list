
+++
authors = ["grid47"]
title = "Leetcode 2923: Find Champion I"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2923: Find Champion I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "23vlLuh_v6c"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-champion-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findChampion(vector<vector<int>>& g) {
        for (int i = 0; i < g.size(); ++i)
            if (accumulate(begin(g[i]), end(g[i]), 0) == g.size() - 1)
                return i;
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2923.md" >}}
---
{{< youtube 23vlLuh_v6c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2924: Find Champion II](https://grid47.xyz/leetcode/solution-2924-find-champion-ii/) |
| --- |
