
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 54: Spiral Matrix"
date = "2024-09-05"
description = "Solution to Leetcode 54"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        int cBgn = 0, cEnd = mtx[0].size()  - 1;
        int rBgn = 0, rEnd = mtx.size() - 1;
        vector<int> ans;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                ans.push_back(mtx[rBgn][i]);
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                ans.push_back(mtx[i][cEnd]);
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                ans.push_back(mtx[rEnd][i]);
            rEnd--;
            if(cBgn <= cEnd)            
            for(int i = rEnd; i >= rBgn; i--)
                ans.push_back(mtx[i][cBgn]);
            cBgn++;
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

