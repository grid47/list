
+++
authors = ["grid47"]
title = "Leetcode 1975: Maximum Matrix Sum"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1975: Maximum Matrix Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1975.md" >}}
---
{{< youtube Qxyne1oRBm0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1976: Number of Ways to Arrive at Destination](https://grid47.xyz/posts/leetcode-1976-number-of-ways-to-arrive-at-destination-solution/) |
| --- |
