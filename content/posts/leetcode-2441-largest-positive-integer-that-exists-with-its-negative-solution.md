
+++
authors = ["grid47"]
title = "Leetcode 2441: Largest Positive Integer That Exists With Its Negative"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2441: Largest Positive Integer That Exists With Its Negative in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int findMaxK(vector<int>& nums) {
    int arr[2001] = {}, res = -1;
    for (int n : nums) {
        if (arr[-n + 1000])
            res = max(res, abs(n));
        ++arr[n + 1000];        
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2441.md" >}}
---
{{< youtube Ec0T3so3m2Y >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2442: Count Number of Distinct Integers After Reverse Operations](https://grid47.xyz/posts/leetcode-2441-largest-positive-integer-that-exists-with-its-negative-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
