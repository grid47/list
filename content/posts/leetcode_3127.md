
+++
authors = ["Crafted by Me"]
title = "Leetcode 3127: Make a Square with the Same Color"
date = "2016-04-10"
description = "Solution to Leetcode 3127"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-a-square-with-the-same-color/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i + 1 < m; i++)
        for(int j = 0; j + 1 < n; j++) {
            
            int white = (grid[i][j] == 'W') + (grid[i + 1][j] == 'W') +
                (grid[i][j + 1] == 'W') + (grid[i + 1][j + 1] == 'W');
            
            int black = (grid[i][j] == 'B') + (grid[i + 1][j] == 'B') +
                (grid[i][j + 1] == 'B') + (grid[i + 1][j + 1] == 'B');            
            
            if((white == 3 && black == 1) || (white == 1 && black == 3) || white == 4 || black == 4)
                return true;
        }
        
        return false;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

