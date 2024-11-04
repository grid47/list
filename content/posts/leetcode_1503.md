
+++
authors = ["Crafted by Me"]
title = "Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int mx = 0;
        for(int i = 0; i < right.size(); i++)
            mx = max(mx, n - right[i]);
        
        for(int i = 0; i < left.size(); i++)
            mx = max(mx, left[i]);        
        
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1503.md" >}}
---
{{< youtube tl0akFR9IXQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1504: Count Submatrices With All Ones](https://grid47.xyz/posts/leetcode_1504) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

