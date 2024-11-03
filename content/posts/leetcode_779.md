
+++
authors = ["Crafted by Me"]
title = "Leetcode 779: K-th Symbol in Grammar"
date = "2022-09-15"
description = "In-depth solution and explanation for Leetcode 779: K-th Symbol in Grammar in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


| Next : [LeetCode #780: Reaching Points](grid47.xyz/leetcode_780) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

