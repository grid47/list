
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2274: Maximum Consecutive Floors Without Special Floors"
date = "2018-08-10"
description = "Solution to Leetcode 2274"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spec) {

        sort(spec.begin(), spec.end());
        int prv = bottom - 1, n = spec.size();

        int res = 0;
        for(int cur : spec) {
            res = max(res, cur - prv - 1);
            prv = cur > prv ? cur : prv;
        }
        res = max(res, top - prv);

        return res;
    }
};

// bottom - top
// spec
// 
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

