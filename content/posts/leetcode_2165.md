
+++
authors = ["grid47"]
title = "Leetcode 2165: Smallest Value of the Rearranged Number"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2165: Smallest Value of the Rearranged Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long smallestNumber(long long num) {
        auto s = to_string(abs(num));
        sort(s.begin(), s.end(), [&](char a, char b){
            return num > 0? a < b: b < a;
        });
        if(num > 0)
        swap(s[0], s[s.find_first_not_of('0')]);
        return stoll(s) * (num < 0? -1: 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2165.md" >}}
---
{{< youtube fe3yn96MAoI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2166: Design Bitset](https://grid47.xyz/posts/leetcode_2166) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
