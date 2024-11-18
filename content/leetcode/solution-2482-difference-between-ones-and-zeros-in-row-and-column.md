
+++
authors = ["grid47"]
title = "Leetcode 2482: Difference Between Ones and Zeros in Row and Column"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2482: Difference Between Ones and Zeros in Row and Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JwuTsHDJVdI"
youtube_upload_date="2023-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/JwuTsHDJVdI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }

        vector<vector<int>> g(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            g[i][j] = 2 * row[i] + 2 * col[j] - m - n;
        }
        return g;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2482.md" >}}
---
{{< youtube JwuTsHDJVdI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2483: Minimum Penalty for a Shop](https://grid47.xyz/leetcode/solution-2483-minimum-penalty-for-a-shop/) |
| --- |
