
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1131: Maximum of Absolute Value Expression"
date = "2021-09-25"
description = "Solution to Leetcode 1131"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
