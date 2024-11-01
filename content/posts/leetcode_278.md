
+++
authors = ["Crafted by Me"]
title = "Leetcode 278: First Bad Version"
date = "2024-01-29"
description = "Solution to Leetcode 278"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-bad-version/description/)

---

**Code:**

{{< highlight cpp >}}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(isBadVersion(mid))
                e = mid;
            else s = mid + 1;
        }
        return e;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/278.md" >}}
---
{{< youtube E15djRphPj0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

