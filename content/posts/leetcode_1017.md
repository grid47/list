
+++
authors = ["Crafted by Me"]
title = "Leetcode 1017: Convert to Base -2"
date = "2022-01-20"
description = "In-depth solution and explanation for Leetcode 1017: Convert to Base -2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-to-base-2/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string baseNeg2(int n) {
        string res = "";

        while(n) {
            res = to_string(n&1) + res;
            n = -(n >> 1);
        }

        return res == ""? "0":res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1017.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

