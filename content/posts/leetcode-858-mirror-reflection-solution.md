
+++
authors = ["grid47"]
title = "Leetcode 858: Mirror Reflection"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 858: Mirror Reflection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/mirror-reflection/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p%2 + q%2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/858.md" >}}
---
{{< youtube fUa0LRtSlz0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #859: Buddy Strings](https://grid47.xyz/posts/leetcode-859-buddy-strings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
