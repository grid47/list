
+++
authors = ["grid47"]
title = "Leetcode 2352: Equal Row and Column Pairs"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2352: Equal Row and Column Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/equal-row-and-column-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int c = 0; c < n; c++) {
            vector<int> col;
            col.reserve(n);
            for(int i = 0; i < n; i++)
            col.push_back(grid[i][c]);
            ans += count(begin(grid), end(grid), col);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2352.md" >}}
---
{{< youtube TmLXO3ZS6Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2353: Design a Food Rating System](https://grid47.xyz/leetcode/solution-2353-design-a-food-rating-system/) |
| --- |
