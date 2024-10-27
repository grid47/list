
+++
authors = ["Yasir"]
title = "Leetcode 48: Rotate Image"
date = "2024-09-10"
description = "Solution to Leetcode 48"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotate-image/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    void rotate(vector<vector<int>>& mtx) {
        int i = 0, j = mtx.size() - 1;
        while(i <= j)
            swap(mtx[i++], mtx[j--]);
        
        for(int i = 0; i < mtx.size(); i++)
        for(int j = i+1; j< mtx.size(); j++)
            swap(mtx[i][j], mtx[j][i]);
    }
};
{{< /highlight >}}

