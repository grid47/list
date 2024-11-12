
+++
authors = ["grid47"]
title = "Leetcode 1557: Minimum Number of Vertices to Reach All Nodes"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1557: Minimum Number of Vertices to Reach All Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ca(n, 0);
        vector<int> ans;
        for(auto e: edges) {
            ca[e[1]]++;
        }
        for(int i = 0; i< n ; i++)
        if(ca[i] == 0) ans.push_back(i);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1557.md" >}}
---
{{< youtube oEy0bzfioG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1559: Detect Cycles in 2D Grid](https://grid47.xyz/posts/leetcode-1559-detect-cycles-in-2d-grid-solution/) |
| --- |
