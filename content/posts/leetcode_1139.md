
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1139: Largest 1-Bordered Square"
date = "2021-09-17"
description = "Solution to Leetcode 1139"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-1-bordered-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> top(m, vector<int>(n, 0)), left(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] > 0) {
                top[i][j] = i > 0? 1 + top[i - 1][j]: 1;
                left[i][j] = j > 0? 1 + left[i][j - 1]: 1;
            }
        
        for(int l = min(m, n); l >= 1; l--) {
            for(int i = 0; i < m - l + 1; i++)
            for(int j = 0; j < n - l + 1; j++)
                if(top[i + l - 1][j] >= l &&
                   top[i + l - 1][j + l - 1] >= l &&
                  left[i][j + l - 1] >= l &&
                  left[i + l - 1][j + l - 1] >= l)
                    return l * l;
        }
        return 0;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
