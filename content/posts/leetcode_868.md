
+++
authors = ["Crafted by Me"]
title = "Leetcode 868: Binary Gap"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 868: Binary Gap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-gap/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        for (int d = -32; n; n >>=1, d++)
            if (n % 2) 
            { 
                res = max(res, d);
                d   = 0;
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/868.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #869: Reordered Power of 2](https://grid47.xyz/posts/leetcode_869) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

