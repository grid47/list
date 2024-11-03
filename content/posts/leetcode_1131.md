
+++
authors = ["Crafted by Me"]
title = "Leetcode 1131: Maximum of Absolute Value Expression"
date = "2021-09-28"
description = "In-depth solution and explanation for Leetcode 1131: Maximum of Absolute Value Expression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

