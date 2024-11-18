
+++
authors = ["grid47"]
title = "Leetcode 1131: Maximum of Absolute Value Expression"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1131: Maximum of Absolute Value Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-of-absolute-value-expression/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0, n = x.size(), smallest, cur;
        for(int p: {1, -1}) {
            for(int q: {1, -1}) {
                smallest = p * x[0] + q * y[0] + 0;
                for(int i = 1; i < n; i++) {
                    cur = p * x[i] + q * y[i] + i;
                    res = max(res, cur - smallest);
                    smallest = min(smallest, cur);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1131.md" >}}
---
{{< youtube cNEQMhXa1uI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1137: N-th Tribonacci Number](https://grid47.xyz/leetcode/solution-1137-n-th-tribonacci-number/) |
| --- |
