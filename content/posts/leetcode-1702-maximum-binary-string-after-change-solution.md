
+++
authors = ["grid47"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1702: Maximum Binary String After Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumBinaryString(string binary) {
        int ones = 0, zeros = 0, n = binary.size();
        for (auto &c: binary) {
            if(c == '0')
            zeros++;
            else if (zeros == 0)
            ones++;
            c = '1';
        }
        if(ones < n)
        binary[zeros + ones -1] = '0';
        return binary;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1702.md" >}}
---
{{< youtube FL972h3KqKA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1704: Determine if String Halves Are Alike](https://grid47.xyz/posts/leetcode-1704-determine-if-string-halves-are-alike-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}