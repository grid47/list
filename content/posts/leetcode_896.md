
+++
authors = ["Crafted by Me"]
title = "Leetcode 896: Monotonic Array"
date = "2022-05-21"
description = "Solution to Leetcode 896"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/monotonic-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/896.md" >}}
- by gpt
        
---
{{< youtube stkYclqstaA >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

