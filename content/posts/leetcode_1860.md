
+++
authors = ["Crafted by Me"]
title = "Leetcode 1860: Incremental Memory Leak"
date = "2019-09-30"
description = "Solution to Leetcode 1860"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/incremental-memory-leak/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int i = 1;
        while(i <= mem1 || i <= mem2) {
            if(mem1 >= mem2) {
                mem1 -= i;
            } else mem2 -= i;
            i++;
        }
        return vector<int>{i, mem1, mem2};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

