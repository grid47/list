
+++
authors = ["grid47"]
title = "Leetcode 279: Perfect Squares"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 279: Perfect Squares in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/perfect-squares/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/279.jpeg" 
    alt="A series of glowing squares being formed from numbers, each square glowing brighter as it becomes perfect."
    caption="Solution to LeetCode 279: Perfect Squares Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSquares(int n) {
        vector<long> cnt(n + 1, INT_MAX);

        cnt[0] = 0;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j * j <= i; j++)
            cnt[i] = min(cnt[i], cnt[i - j * j] + 1);

        return cnt[n];

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/279.md" >}}
---
{{< youtube HLZLwjzIVGo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #283: Move Zeroes](https://grid47.xyz/posts/leetcode-283-move-zeroes-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}