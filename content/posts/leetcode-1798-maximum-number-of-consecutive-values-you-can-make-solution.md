
+++
authors = ["grid47"]
title = "Leetcode 1798: Maximum Number of Consecutive Values You Can Make"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1798: Maximum Number of Consecutive Values You Can Make in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int res = 1;
        for(int a: coins) {
            if(a > res) break;
            // with all the coins I have I can 
            // create upto res - 1,
            // with this a, I can make upto res + a - 1
            // so next target is res += a
            res += a;
        }

        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1798.md" >}}
---
{{< youtube 3ONSGo28_Z0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1799: Maximize Score After N Operations](https://grid47.xyz/posts/leetcode-1799-maximize-score-after-n-operations-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}