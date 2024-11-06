
+++
authors = ["Crafted by Me"]
title = "Leetcode 42: Trapping Rain Water"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 42: Trapping Rain Water in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Dynamic Programming","Stack","Monotonic Stack"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/trapping-rain-water/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int trap(vector<int>& n) {
        int l = 0, r = n.size() - 1, ans = 0, ml = 0, mr = 0;
        while (l < r)
            if (n[l] < n[r]) ans += (ml = max(ml, n[l])) - n[l++];
            else ans += (mr = max(mr, n[r])) - n[r--];
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/42.md" >}}
---
{{< youtube KFdHpOlz8hs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #43: Multiply Strings](https://grid47.xyz/posts/leetcode_43) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
