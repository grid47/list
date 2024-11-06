
+++
authors = ["Crafted by Me"]
title = "Leetcode 873: Length of Longest Fibonacci Subsequence"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 873: Length of Longest Fibonacci Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int res = 2, n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], l = 2;
                while(s.count(a + b))
                b = a + b, a = b - a, l++;
                res = max(res, l);
            }            
        }

        return res > 2? res: 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/873.md" >}}
---
{{< youtube BWj2qT3aTrA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #874: Walking Robot Simulation](https://grid47.xyz/posts/leetcode_874) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
