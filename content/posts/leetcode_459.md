
+++
authors = ["Crafted by Me"]
title = "Leetcode 459: Repeated Substring Pattern"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 459: Repeated Substring Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/repeated-substring-pattern/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        return (str + str).substr(1, str.size() * 2 - 2).find(str)!=-1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/459.md" >}}
---
{{< youtube p92_kEjyJAo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #467: Unique Substrings in Wraparound String](https://grid47.xyz/posts/leetcode_467) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
