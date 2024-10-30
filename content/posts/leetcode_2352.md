
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2352: Equal Row and Column Pairs"
date = "2018-05-24"
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
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

