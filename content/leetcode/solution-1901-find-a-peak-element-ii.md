
+++
authors = ["grid47"]
title = "Leetcode 1901: Find a Peak Element II"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1901: Find a Peak Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-a-peak-element-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            int row = 0;
            for(int i = 0; i < m; i++)
                row = mat[i][mid] >= mat[row][mid]? i: row;
            
            int isRightLarger = mid + 1 <= r ? mat[row][mid + 1] > mat[row][mid]: false;
            int isLeftLarger = mid - 1 >= l  ? mat[row][mid - 1] > mat[row][mid]: false;            
            
            if(!isRightLarger && !isLeftLarger)
                return vector<int>{row, mid};
            
            if(isRightLarger) l = mid + 1;
            else             r = mid - 1;
            
        }
        return vector<int>{-1, -1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1901.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1903: Largest Odd Number in String](https://grid47.xyz/leetcode/solution-1903-largest-odd-number-in-string/) |
| --- |
