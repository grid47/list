
+++
authors = ["grid47"]
title = "Leetcode 73: Set Matrix Zeroes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 73: Set Matrix Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/set-matrix-zeroes/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/73.jpeg" 
    alt="A calm matrix with soft light illuminating areas that need to be reset to zero."
    caption="Solution to LeetCode 73: Set Matrix Zeroes Problem"
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
---
{{< youtube T41rL0L3Pnw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #74: Search a 2D Matrix](https://grid47.xyz/posts/leetcode-74-search-a-2d-matrix-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}