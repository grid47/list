
+++
authors = ["grid47"]
title = "Leetcode 2906: Construct Product Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2906: Construct Product Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-product-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>xx(n,vector<int>(m));
        vector<vector<int>>yy(n,vector<int>(m));
        
        
        
        int mod = 12345;
        long long p = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                xx[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }
        p = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                yy[i][j] = p;
                p *= grid[i][j];
                p %= mod;
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                long long mul = xx[i][j] * yy[i][j];
                
                ans[i][j] = mul%mod;
            }
        }
        return ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2906.md" >}}
---
{{< youtube CXuoLKjEWIs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2908: Minimum Sum of Mountain Triplets I](https://grid47.xyz/posts/leetcode-2908-minimum-sum-of-mountain-triplets-i-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}