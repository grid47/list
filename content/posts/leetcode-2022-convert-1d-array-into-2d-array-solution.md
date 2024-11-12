
+++
authors = ["grid47"]
title = "Leetcode 2022: Convert 1D Array Into 2D Array"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2022: Convert 1D Array Into 2D Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-1d-array-into-2d-array/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2022.md" >}}
---
{{< youtube l-VLzZ2riTc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2023: Number of Pairs of Strings With Concatenation Equal to Target](https://grid47.xyz/posts/leetcode-2023-number-of-pairs-of-strings-with-concatenation-equal-to-target-solution/) |
| --- |
