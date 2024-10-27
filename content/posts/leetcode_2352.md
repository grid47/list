
+++
authors = ["Yasir"]
title = "Leetcode 2352: Equal Row and Column Pairs"
date = "2018-05-21"
description = "Solution to Leetcode 2352"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/equal-row-and-column-pairs/description/)

---

**Code:**

{{< highlight html >}}
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

