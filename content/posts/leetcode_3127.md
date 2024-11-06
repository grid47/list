
+++
authors = ["Crafted by Me"]
title = "Leetcode 3127: Make a Square with the Same Color"
date = "2024-11-01"
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


---
{{< youtube 6krFbmlIg94 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3128: Right Triangles](https://grid47.xyz/posts/leetcode_3128) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

