
+++
authors = ["Crafted by Me"]
title = "Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int minimumRecolors(string blocks, int k) {
    int b = 0, mb = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        b += blocks[i] == 'B';
        if (i >= k)
            b -= blocks[i - k] == 'B';
        mb = max(b, mb);
    }
    return k - mb;
}
};
{{< /highlight >}}


---
{{< youtube RRmSKRsT9tg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2380: Time Needed to Rearrange a Binary String](https://grid47.xyz/posts/leetcode_2380) |
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
