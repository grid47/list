
+++
authors = ["Crafted by Me"]
title = "Leetcode 2711: Difference of Number of Distinct Values on Diagonals"
date = "2017-05-31"
description = "Solution to Leetcode 2711"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

