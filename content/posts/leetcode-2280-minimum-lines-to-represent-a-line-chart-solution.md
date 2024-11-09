
+++
authors = ["grid47"]
title = "Leetcode 2280: Minimum Lines to Represent a Line Chart"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2283: Check if Number Has Equal Digit Count and Digit Value](https://grid47.xyz/posts/leetcode-2283-check-if-number-has-equal-digit-count-and-digit-value-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
