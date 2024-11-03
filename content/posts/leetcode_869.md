
+++
authors = ["Crafted by Me"]
title = "Leetcode 869: Reordered Power of 2"
date = "2022-06-17"
description = "In-depth solution and explanation for Leetcode 869: Reordered Power of 2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reordered-power-of-2/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int c = counter(n);
        for(int i = 0; i < 32; i++)
            if(counter(1<<i) == c) return true;
        return false;
    }

    int counter(int N) {
        int res = 0;
        for(;N; N/=10) res += pow(10, N%10);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/869.md" >}}
---


"| 870: Advantage Shuffle |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

