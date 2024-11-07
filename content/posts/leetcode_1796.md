
+++
authors = ["Crafted by Me"]
title = "Leetcode 1796: Second Largest Digit in a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1796: Second Largest Digit in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/second-largest-digit-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int secondHighest(string s) {
        // support variables
        int res[2] = {-1, -1};
        // parsing s
        for (char c: s) {
            // considering only numerical characters
            if (c >= '0' && c <= '9') {
                // normalising c
                c -= '0';
                // updating res
                if (c > res[0]) {
                    res[1] = res[0];
                    res[0] = c;
                } else if (c != res[0] && c > res[1]) res[1] = c;
            }
        }
        return res[1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1796.md" >}}
---
{{< youtube hyQUsjKrq1s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1797: Design Authentication Manager](https://grid47.xyz/posts/leetcode_1797) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
