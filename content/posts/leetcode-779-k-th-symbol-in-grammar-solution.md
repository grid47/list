
+++
authors = ["grid47"]
title = "Leetcode 779: K-th Symbol in Grammar"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 779: K-th Symbol in Grammar in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-th-symbol-in-grammar/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)   return 0;
        if (k%2 == 0) return kthGrammar(n - 1,       k / 2) == 0? 1 : 0;
        else          return kthGrammar(n - 1, (k + 1) / 2) == 0? 0 : 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/779.md" >}}
---
{{< youtube pmD2HCKaqRQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #780: Reaching Points](https://grid47.xyz/posts/leetcode-779-k-th-symbol-in-grammar-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
