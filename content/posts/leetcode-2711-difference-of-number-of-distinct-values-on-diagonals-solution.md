
+++
authors = ["grid47"]
title = "Leetcode 2711: Difference of Number of Distinct Values on Diagonals"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2711: Difference of Number of Distinct Values on Diagonals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        set<int> ls, rs;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            int r = i - 1, c = j - 1;
            
            while(r >= 0 && c >= 0) {
                ls.insert(grid[r][c]);
                r--;
                c--;
            }
            
            r = i + 1, c = j + 1;
            
            while(r < m && c < n) {
                rs.insert(grid[r][c]);
                r++;
                c++;
            }
            int res = ls.size() - rs.size();
            ans[i][j] = abs(res);
            ls.clear();
            rs.clear();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2711.md" >}}
---
{{< youtube i166oIOHaPE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2712: Minimum Cost to Make All Characters Equal](https://grid47.xyz/posts/leetcode-2712-minimum-cost-to-make-all-characters-equal-solution/) |
| --- |
