
+++
authors = ["grid47"]
title = "Leetcode 2397: Maximum Rows Covered by Columns"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2397: Maximum Rows Covered by Columns in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-rows-covered-by-columns/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumRows(vector<vector<int>>& mtx, int sel) {
        int m = mtx.size(), n = mtx[0].size();
        
        int ans = 0;
        for(int msk = 0; msk < (1 << n); msk++) {
            if(__builtin_popcount(msk) != sel) continue;
            int res = 0;
            for(int i = 0; i < m; i++) {
                bool take = true;
                for(int j = 0; j < n; j++)
                    if(mtx[i][j] && (((msk >> j) & 1) == 0)) {
                        take = false;
                        break;
                    }
                if(take) res++;
            }
            ans = max(ans, res);
        }
        
        
        return ans;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2397.md" >}}
---
{{< youtube scBL7uQiPMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2399: Check Distances Between Same Letters](https://grid47.xyz/posts/leetcode-2399-check-distances-between-same-letters-solution/) |
| --- |
