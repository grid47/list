
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 73: Set Matrix Zeroes"
date = "2024-08-17"
description = "Solution to Leetcode 73"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/set-matrix-zeroes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void setZeroes(vector<vector<int>>& mtx) {
        int m = mtx.size(), n = mtx[0].size();
        int zr = 0, zc = 0;
        for(int i = 0; i < n; i++)
            if(mtx[0][i] == 0) zr = 1;
        for(int i = 0; i < m; i++)
            if(mtx[i][0] == 0) zc = 1;        
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(mtx[i][j] == 0) {
                mtx[i][0] = 0;
                mtx[0][j] = 0;
            }
        
        for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            if(mtx[i][0] == 0 || mtx[0][j] == 0)
                mtx[i][j] = 0;
        
        if(zr == 1)
        for(int i = 0; i < n; i++)
            mtx[0][i] = 0;
        if(zc == 1)
        for(int i = 0; i < m; i++)
            mtx[i][0] = 0;        
            
        
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/73.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

