
+++
authors = ["Crafted by Me"]
title = "Leetcode 2000: Reverse Prefix of Word"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2000: Reverse Prefix of Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-prefix-of-word/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(begin(word), begin(word) + p + 1);
        return word;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2000.md" >}}
---
{{< youtube jVRdLKA6t4k >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2001: Number of Pairs of Interchangeable Rectangles](https://grid47.xyz/posts/leetcode_2001) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
