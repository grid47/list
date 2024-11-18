
+++
authors = ["grid47"]
title = "Leetcode 885: Spiral Matrix III"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 885: Spiral Matrix III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res = {{rStart, cStart}};
        int dx = 0, dy = 1, tmp;
        for(int n = 0; res.size() < rows* cols; n++) {
            for(int i = 0; i < n / 2 + 1; i++) {
                rStart += dx, cStart += dy;
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    res.push_back({rStart, cStart});
                
            }
            tmp = dx, dx = dy, dy = -tmp;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/885.md" >}}
---
{{< youtube 0qep3f9cqVs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #886: Possible Bipartition](https://grid47.xyz/leetcode/solution-886-possible-bipartition/) |
| --- |
