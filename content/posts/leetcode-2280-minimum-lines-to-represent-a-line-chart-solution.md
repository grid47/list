
+++
authors = ["grid47"]
title = "Leetcode 2280: Minimum Lines to Represent a Line Chart"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2280: Minimum Lines to Represent a Line Chart in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry","Sorting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLines(vector<vector<int>>& stk) {
        
        sort(stk.begin(), stk.end());
        
        int res = 1, n = stk.size();
        if (n < 2) return 0;

        for(int i = 2; i < n; i++) {
            long x1 = stk[i][0], x2 = stk[i - 1][0], x3 = stk[i - 2][0];
            long y1 = stk[i][1], y2 = stk[i - 1][1], y3 = stk[i - 2][1];
            
            long diff1 = (y3 - y2) * (x2 - x1);
            long diff2 = (y2 - y1) * (x3 - x2);
            
            if (diff1 != diff2) res++;
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2280.md" >}}
---
{{< youtube EkoNpVUBSVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2283: Check if Number Has Equal Digit Count and Digit Value](https://grid47.xyz/posts/leetcode-2283-check-if-number-has-equal-digit-count-and-digit-value-solution/) |
| --- |
