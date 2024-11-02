
+++
authors = ["Crafted by Me"]
title = "Leetcode 2849: Determine if a Cell Is Reachable at a Given Time"
date = "2016-01-14"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

