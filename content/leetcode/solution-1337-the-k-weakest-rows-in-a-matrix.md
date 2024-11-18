
+++
authors = ["grid47"]
title = "Leetcode 1337: The K Weakest Rows in a Matrix"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1337: The K Weakest Rows in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Heap (Priority Queue)","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1337.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1338: Reduce Array Size to The Half](https://grid47.xyz/leetcode/solution-1338-reduce-array-size-to-the-half/) |
| --- |
