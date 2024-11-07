
+++
authors = ["Crafted by Me"]
title = "Leetcode 2826: Sorting Three Groups"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2826: Sorting Three Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sorting-three-groups/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& A) {
        int a = 0, b = 0, c = 0;
        for (int x: A) {
            a += x != 1;
            b = min(a, b + (x != 2));
            c = min(b, c + (x != 3));
        }
        return c;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2826.md" >}}
---
{{< youtube Q3wrIhMmpfA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2828: Check if a String Is an Acronym of Words](https://grid47.xyz/posts/leetcode_2828) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
