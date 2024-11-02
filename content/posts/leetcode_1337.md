
+++
authors = ["Crafted by Me"]
title = "Leetcode 1337: The K Weakest Rows in a Matrix"
date = "2020-03-05"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

