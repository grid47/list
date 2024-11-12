
+++
authors = ["grid47"]
title = "Leetcode 807: Max Increase to Keep City Skyline"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 807: Max Increase to Keep City Skyline in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            res += min(row[i], col[j]) - grid[i][j];
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/807.md" >}}
---
{{< youtube uVPkYy5jzRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #808: Soup Servings](https://grid47.xyz/posts/leetcode-808-soup-servings-solution/) |
| --- |
