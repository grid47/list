
+++
authors = ["grid47"]
title = "Leetcode 3127: Make a Square with the Same Color"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3127: Make a Square with the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3127.md" >}}
---
{{< youtube 6krFbmlIg94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #3128: Right Triangles](https://grid47.xyz/posts/leetcode-3128-right-triangles-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
