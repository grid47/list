
+++
authors = ["Yasir"]
title = "Leetcode 1337: The K Weakest Rows in a Matrix"
date = "2021-03-01"
description = "Solution to Leetcode 1337"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        for(int i=0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for(int i=0; i<k; i++){
            ans[i]=mat[i][n];            
        }
        return ans;
    }
};
{{< /highlight >}}

