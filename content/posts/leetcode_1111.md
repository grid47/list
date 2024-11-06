
+++
authors = ["Crafted by Me"]
title = "Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> groups;
        int d = 0;
        for(char c: seq) {
            bool open = c == '(';
            if(open) d++;
            groups.push_back(d%2);
            if(!open) d--;
        }
        return groups;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1111.md" >}}
---
{{< youtube lHzdbjyqBG4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1112: Highest Grade For Each Student](https://grid47.xyz/posts/leetcode_1112) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
