
+++
authors = ["Crafted by Me"]
title = "Leetcode 1420: Build Array Where You Can Find The Maximum Exactly K Comparisons"
date = "2020-12-12"
description = "Solution to Leetcode 1420"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int mod = (int) 1e9 + 7;

    int numOfArrays(int n, int m, int k) {

        vector<vector<vector<int>>> ways =
            vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

        for(int j = 1; j <= m; j++) ways[1][j][1] = 1;

        for (int ii = 1; ii <= n; ii++)
        for (int ij = 1; ij <= m; ij++)
        for (int ik = 1; ik <= k; ik++) {

            long s = ((long) ij * ways[ii - 1][ij][ik]) % mod;
            for(int l = 1; l < ij; l++) s = (s + ways[ii - 1][l][ik - 1]) % mod;
            ways[ii][ij][ik] = (ways[ii][ij][ik] + s) % mod;

        }

        long res = 0;
        for(int ii = 1; ii <= m; ii++) res = (res + ways[n][ii][k]) % mod;
        
        return (int) res;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

