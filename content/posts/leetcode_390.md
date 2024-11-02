
+++
authors = ["Crafted by Me"]
title = "Leetcode 390: Elimination Game"
date = "2022-10-08"
description = "Solution to Leetcode 390"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/elimination-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int rm = n;
        int step = 1;
        int head = 1;
        while(rm > 1) {
            if(left || rm % 2 == 1) {
                head += step;
            }
            rm /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/390.md" >}}
---
{{< youtube 0U5Lenn_vMo >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

