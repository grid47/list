
+++
authors = ["grid47"]
title = "Leetcode 1768: Merge Strings Alternately"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1768: Merge Strings Alternately in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-strings-alternately/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int i = 0, j = 0;
        while(i < w1.size() || j < w2.size()) {
            if(i < w1.size()) {
                res += w1[i];
                i++;
            }
            if(j < w2.size()) {
                res += w2[j];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1768.md" >}}
---
{{< youtube oFuFTMu2Tgg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1769: Minimum Number of Operations to Move All Balls to Each Box](https://grid47.xyz/posts/leetcode_1769) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
