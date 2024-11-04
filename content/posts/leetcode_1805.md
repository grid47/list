
+++
authors = ["Crafted by Me"]
title = "Leetcode 1805: Number of Different Integers in a String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1805: Number of Different Integers in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    
        for (int i = 0, j = 0; j <= w.size(); ++j) {
            if (j < w.size() && isdigit(w[j]))
                i += i < j && w[i] == '0';
            else {
                s.insert(w.substr(i, j - i));
                i = j + 1;
            }
        }
        return s.size() - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1805.md" >}}
---
{{< youtube 1vZ2c92YgOc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1806: Minimum Number of Operations to Reinitialize a Permutation](https://grid47.xyz/posts/leetcode_1806) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

