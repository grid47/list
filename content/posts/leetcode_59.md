
+++
authors = ["Yasir"]
title = "Leetcode 59: Spiral Matrix II"
date = "2024-08-31"
description = "Solution to Leetcode 59"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-ii/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

