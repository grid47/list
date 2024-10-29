
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2849: Determine if a Cell Is Reachable at a Given Time"
date = "2017-01-11"
description = "Solution to Leetcode 2849"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int mn = min(abs(fy - sy), abs(fx - sx));
        int asdf = (abs(fy - sy) - mn)+ (abs(fx - sx) - mn) + mn;
        if(abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
        return asdf <= t;

    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

