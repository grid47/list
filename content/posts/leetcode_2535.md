
+++
authors = ["Crafted by Me"]
title = "Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int dsum(int v) {
    return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
int differenceOfSum(vector<int>& n) {
    return abs(accumulate(begin(n), end(n), 0) - 
        accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2535.md" >}}
---
{{< youtube wg-szN5zvr4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2536: Increment Submatrices by One](https://grid47.xyz/posts/leetcode_2536) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
