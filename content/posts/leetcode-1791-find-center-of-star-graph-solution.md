
+++
authors = ["grid47"]
title = "Leetcode 1791: Find Center of Star Graph"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1791: Find Center of Star Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-center-of-star-graph/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1791.md" >}}
---
{{< youtube jBD2_Eh4SlU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1792: Maximum Average Pass Ratio](https://grid47.xyz/posts/leetcode-1792-maximum-average-pass-ratio-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}