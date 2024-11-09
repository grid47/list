
+++
authors = ["grid47"]
title = "Leetcode 955: Delete Columns to Make Sorted II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 955: Delete Columns to Make Sorted II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #956: Tallest Billboard](https://grid47.xyz/posts/leetcode-956-tallest-billboard-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
