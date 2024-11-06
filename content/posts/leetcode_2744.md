
+++
authors = ["Crafted by Me"]
title = "Leetcode 2744: Find Maximum Number of String Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2744: Find Maximum Number of String Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
    int vis[676] = {}, res = 0;
    for (const auto &w : words) {
        res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
        vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
    }
    return res;
}
};
{{< /highlight >}}


---
{{< youtube f8qWoxowloA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2745: Construct the Longest New String](https://grid47.xyz/posts/leetcode_2745) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
