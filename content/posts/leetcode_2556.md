
+++
authors = ["Yasir"]
title = "Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip"
date = "2017-10-30"
description = "Solution to Leetcode 2556"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

