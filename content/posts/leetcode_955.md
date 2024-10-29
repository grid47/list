
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 955: Delete Columns to Make Sorted II"
date = "2022-03-20"
description = "Solution to Leetcode 955"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

