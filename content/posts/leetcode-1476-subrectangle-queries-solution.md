
+++
authors = ["grid47"]
title = "Leetcode 1476: Subrectangle Queries"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1476: Subrectangle Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subrectangle-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class SubrectangleQueries {
public:
    vector<vector<int>> rec;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++)
        for(int j = col1; j <= col2; j++)
            rec[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1476.md" >}}
---
{{< youtube cMBkZMNVDdE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1477: Find Two Non-overlapping Sub-arrays Each With Target Sum](https://grid47.xyz/posts/leetcode-1477-find-two-non-overlapping-sub-arrays-each-with-target-sum-solution/) |
| --- |
