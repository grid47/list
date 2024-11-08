
+++
authors = ["grid47"]
title = "Leetcode 2259: Remove Digit From Number to Maximize Result"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2259: Remove Digit From Number to Maximize Result in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDigit(string n, char digit) {
        for (int i = 0; i < n.size() - 1; ++i)
            if (n[i] == digit && n[i + 1] > digit)
                return n.substr(0, i) + n.substr(i + 1);
        int last_d = n.rfind(digit);
        return n.substr(0, last_d) + n.substr(last_d + 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2259.md" >}}
---
{{< youtube cinEIxOL0E8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2260: Minimum Consecutive Cards to Pick Up](https://grid47.xyz/posts/leetcode_2260) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
