
+++
authors = ["grid47"]
title = "Leetcode 3178: Find the Child Who Has the Ball After K Seconds"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3178: Find the Child Who Has the Ball After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfChild(int n, int k) {
        int up = false, idx = 0;
        for(int i = 0; i < k; i++) {

            if (idx == n - 1 || idx == 0) up = !up;

            if (up) idx++;
            else    idx--;

        }
        return idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3178.md" >}}
---
{{< youtube JX-J9LZxqvk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3179: Find the N-th Value After K Seconds](https://grid47.xyz/posts/leetcode-3179-find-the-n-th-value-after-k-seconds-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
