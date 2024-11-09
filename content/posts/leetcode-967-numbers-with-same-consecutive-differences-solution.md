
+++
authors = ["grid47"]
title = "Leetcode 967: Numbers With Same Consecutive Differences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 967: Numbers With Same Consecutive Differences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 2; i <= n; i++) {
            vector<int> cur2;
            for(int x: cur) {
                int y = x % 10;
                if(y + k < 10)
                    cur2.push_back(x * 10 + y + k);
                if(k>0 && y - k >= 0)
                    cur2.push_back(x * 10 + y - k);
                
            }
            cur = cur2;
        }
        return cur;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/967.md" >}}
---
{{< youtube TAfXh2l9FyA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #968: Binary Tree Cameras](https://grid47.xyz/posts/leetcode-967-numbers-with-same-consecutive-differences-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
