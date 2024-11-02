
+++
authors = ["Crafted by Me"]
title = "Leetcode 2582: Pass the Pillow"
date = "2016-10-07"
description = "Solution to Leetcode 2582"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pass-the-pillow/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
        int passThePillow(int n, int time) {
            return n - abs(n - 1 - time % (n * 2 - 2));
        }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

