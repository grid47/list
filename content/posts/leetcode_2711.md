
+++
authors = ["Crafted by Me"]
title = "Leetcode 2711: Difference of Number of Distinct Values on Diagonals"
date = "2024-11-01"
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


---
{{< youtube i166oIOHaPE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2712: Minimum Cost to Make All Characters Equal](https://grid47.xyz/posts/leetcode_2712) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
