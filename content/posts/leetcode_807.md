
+++
authors = ["Yasir"]
title = "Leetcode 807: Max Increase to Keep City Skyline"
date = "2022-08-13"
description = "Solution to Leetcode 807"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/)

---

**Code:**

{{< highlight html >}}
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

