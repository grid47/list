
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1975: Maximum Matrix Sum"
date = "2019-06-04"
description = "Solution to Leetcode 1975"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-matrix-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        

        long long sum = 0;
        bool isodd = n % 2;
        int cnt = 0;
        int mn = abs(mat[0][0]);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            
            if(mat[i][j] < 0) cnt++;
            
            mn = min(mn, abs(mat[i][j]));
            sum += abs(mat[i][j]);            
        }

        if(cnt%2 == 1)
            sum -= (2 *mn);
        
        return sum;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
