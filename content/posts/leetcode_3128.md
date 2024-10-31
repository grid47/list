
+++
authors = ["Crafted by Me"]
title = "Leetcode 3128: Right Triangles"
date = "2016-04-09"
description = "Solution to Leetcode 3128"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/right-triangles/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> hr = grid;
        vector<vector<int>> vr = grid;        
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                hr[i][j] += hr[i][j - 1];
                // cout << hr[i][j] << " ";
            }
            // cout << "\n";
        }


        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vr[i][j] += vr[i - 1][j];            
                // cout << vr[i][j] << " ";
            }
            // cout << "\n";
        }


        long long  cnt = 0, net;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                // if(i == 1 && j == 1) {
                //     cout << ((vr[m - 1][j] - vr[i][j]) + (i >= 1? vr[i - 1][j]: 0));                    
                // }

                net = (hr[i][n - 1] - 1) * ((vr[m - 1][j] - vr[i][j]) + (i > 0? vr[i - 1][j]: 0));
                // cout << i << " " << j << " " << net << "\n";
                cnt += net;
                
            }
        }        
        return cnt;
        
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

