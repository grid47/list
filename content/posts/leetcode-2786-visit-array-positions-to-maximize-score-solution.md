
+++
authors = ["grid47"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2786: Visit Array Positions to Maximize Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxScore(vector<int>& n, int x) {
        long long eve = n[0] - (n[0] % 2 ? x : 0);
        long long odd = n[0] - (n[0] % 2 ? 0 : x);
        for (int i = 1; i < n.size(); ++i)
            if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
            else            eve = n[i] + max(eve, odd - x);
        return max(eve, odd);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2786.md" >}}
---
{{< youtube JtogyeIxGWE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2788: Split Strings by Separator](https://grid47.xyz/posts/leetcode-2788-split-strings-by-separator-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}