
+++
authors = ["Yasir"]
title = "Leetcode 2022: Convert 1D Array Into 2D Array"
date = "2019-04-16"
description = "Solution to Leetcode 2022"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-1d-array-into-2d-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        
        vector<vector<int>> res;
        for (int i = 0; i < m*n; i+=n)
            res.push_back(vector<int>(original.begin()+i, original.begin()+i+n));
            
        return res;
    }
};
{{< /highlight >}}

