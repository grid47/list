
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1074: Number of Submatrices That Sum to Target"
date = "2021-11-20"
description = "Solution to Leetcode 1074"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mtx, int post) {
        int res = 0, m = mtx.size(), n = mtx[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 1; j < n; j++)
        mtx[i][j] += mtx[i][j - 1];
        
        map<int, int> maap;
        // int res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            int cur = 0;
            maap.clear();
            maap[0] = 1;
            for(int k = 0; k < m; k++) {
                cur += mtx[k][j] - ((i > 0) ? mtx[k][i - 1] : 0);
                res += maap[cur - post];
                maap[cur]++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

