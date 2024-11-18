
+++
authors = ["grid47"]
title = "Leetcode 955: Delete Columns to Make Sorted II"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 955: Delete Columns to Make Sorted II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, m = strs.size(), n = strs[0].size();
        int i , j;
        vector<bool> sorted(m - 1, false);
        for(j = 0; j < n; j++) {
            for(i = 0; i < m - 1; i++) {
                if(!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if(i < m - 1) continue;
            for(i = 0; i < m - 1; i++) {
                sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/955.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #957: Prison Cells After N Days](https://grid47.xyz/leetcode/solution-957-prison-cells-after-n-days/) |
| --- |
