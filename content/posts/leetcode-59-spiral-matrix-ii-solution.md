
+++
authors = ["grid47"]
title = "Leetcode 59: Spiral Matrix II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 59: Spiral Matrix II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/59.webp" 
    alt="A dynamic, growing spiral matrix with radiant paths expanding outward."
    caption="Solution to LeetCode 59: Spiral Matrix II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mtx(n, vector<int>(n, 0));
        int cBgn = 0, cEnd = n - 1, rBgn = 0, rEnd = n - 1;
        
        int num = 1;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                mtx[rBgn][i] = num++;
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                mtx[i][cEnd] = num++;
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                mtx[rEnd][i] = num++;
            rEnd--;
            if(cBgn <= cEnd)
            for(int i = rEnd; i >= rBgn; i--)
                mtx[i][cBgn] = num++;
            cBgn++;            
        }
        return mtx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/59.md" >}}
---
{{< youtube RvLrWFBJ9fM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #62: Unique Paths](https://grid47.xyz/posts/leetcode-62-unique-paths-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
