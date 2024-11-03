
+++
authors = ["Crafted by Me"]
title = "Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2557: Maximum Number of Integers to Choose From a Range II](https://grid47.xyz/posts/leetcode_2557) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

