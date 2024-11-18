
+++
authors = ["grid47"]
title = "Leetcode 1267: Count Servers that Communicate"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1267: Count Servers that Communicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-servers-that-communicate/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((grid[i][j] == 1) && ((row[i] > 1) || (col[j] > 1))) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1267.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1268: Search Suggestions System](https://grid47.xyz/leetcode/solution-1268-search-suggestions-system/) |
| --- |
