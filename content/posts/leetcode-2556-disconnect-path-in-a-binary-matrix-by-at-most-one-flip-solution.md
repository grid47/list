
+++
authors = ["grid47"]
title = "Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> grid, memo;
    int m, n;
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid= grid;

        if(isconnected(0, 0) == false) return true;
        this->grid[0][0] = 1;
        return !isconnected(0, 0);
    }
    
    bool isconnected(int i, int j) {
        if(i == m - 1 && j == n - 1) return true;
        
        if(i >= m || j >= n || grid[i][j] == 0) return false;
        
        grid[i][j] = 0;
        return isconnected(i + 1, j) || isconnected(i, j + 1);

    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2556.md" >}}
---
{{< youtube JvRANmpcKcs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2558: Take Gifts From the Richest Pile](https://grid47.xyz/posts/leetcode-2558-take-gifts-from-the-richest-pile-solution/) |
| --- |
