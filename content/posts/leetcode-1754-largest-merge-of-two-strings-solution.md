
+++
authors = ["grid47"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1754: Largest Merge Of Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-merge-of-two-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestMerge(string w1, string w2) {
        if (w1 == "" || w2 == "")
            return w1 + w2;
        else if (w1 < w2)
            return w2[0] + largestMerge(w1, w2.substr(1));
        else return w1[0] + largestMerge(w1.substr(1), w2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1754.md" >}}
---
{{< youtube YB-A6OUj98o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1758: Minimum Changes To Make Alternating Binary String](https://grid47.xyz/posts/leetcode-1758-minimum-changes-to-make-alternating-binary-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}