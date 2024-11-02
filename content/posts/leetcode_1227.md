
+++
authors = ["Crafted by Me"]
title = "Leetcode 1227: Airplane Seat Assignment Probability"
date = "2021-06-24"
description = "Solution to Leetcode 1227"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/airplane-seat-assignment-probability/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        return 1/2.0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1227.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

