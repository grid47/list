
+++
authors = ["Crafted by Me"]
title = "Leetcode 2267:  Check if There Is a Valid Parentheses String Path"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2267:  Check if There Is a Valid Parentheses String Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> mem;
    vector<vector<char>> grid;
    
    int dfs(int i, int j, int cnt) {

        int ans = grid[i][j] == ')'? -1: 1;        

        if(cnt < 0) return false;
        if((i == m - 1) && (j == n - 1)) return (cnt + ans) == 0;
        
        if(mem[i][j][cnt + 220] != -1) return mem[i][j][cnt + 220];

        if(i + 1 < m)
        if(dfs(i + 1, j, cnt + ans)) return true;

        if(j + 1 < n)        
        if(dfs(i, j + 1, cnt + ans)) return true;

        return mem[i][j][cnt + 220] = false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        mem.resize(m, vector<vector<int>>(n, vector<int>(n + m + 1 + 220, -1)));
        this->grid = grid;

        return dfs(0, 0, 0);
        
    }
};
{{< /highlight >}}


---
{{< youtube D9BjcJhHoqY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2268: Minimum Number of Keypresses](https://grid47.xyz/posts/leetcode_2268) |
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
