
+++
authors = ["Crafted by Me"]
title = "Leetcode 2706: Buy Two Chocolates"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2706: Buy Two Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/buy-two-chocolates/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        int l1 = 200, l2 = 200;
        for(int i = 0; i < p.size(); i++) {
            if(p[i] < l1) {
                l2 = l1;
                l1 = p[i];
            } else if(p[i] < l2) {
                l2 = p[i];
            }
        }
        
        if(l1 + l2 <= m) return m - l1 - l2;
        return m;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2706.md" >}}
---
{{< youtube BTzNimiQdW4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2707: Extra Characters in a String](https://grid47.xyz/posts/leetcode_2707) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
