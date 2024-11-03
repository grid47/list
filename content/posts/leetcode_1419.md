
+++
authors = ["Crafted by Me"]
title = "Leetcode 1419: Minimum Number of Frogs Croaking"
date = "2020-12-14"
description = "In-depth solution and explanation for Leetcode 1419: Minimum Number of Frogs Croaking in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {}, frogs = 0, max_frog = 0;
        for(auto ch : croakOfFrogs) {
            auto n = string("croak").find(ch);
            ++cnt[n];
            if(n == 0) max_frog = max(max_frog, ++frogs);
            else if(--cnt[n - 1] < 0)   return -1;
            else if(n == 4)             --frogs;
        }
        return frogs == 0? max_frog : -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1419.md" >}}
---


"| 1420: Build Array Where You Can Find The Maximum Exactly K Comparisons |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

