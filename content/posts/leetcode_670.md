
+++
authors = ["Crafted by Me"]
title = "Leetcode 670: Maximum Swap"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 670: Maximum Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-swap/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSwap(int num) {

        vector<int> idx(10, 0);

        string nm = to_string(num);
        for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

        for(int i = 0; i < nm.size(); i++)
        for(int j = 9; j > nm[i] - '0'; j--) {
            if(idx[j] > i) {
                swap(nm[idx[j]], nm[i]);
                return stoi(nm);
            }
        }

        return num;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/670.md" >}}
---
{{< youtube arecn8VuQL0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #671: Second Minimum Node In a Binary Tree](https://grid47.xyz/posts/leetcode_671) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
