
+++
authors = ["Crafted by Me"]
title = "Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string og = num;
        while(k--) {
            next_permutation(num.begin(), num.end());
        }
        return steps(og, num);
    }

    int steps(string s1, string s2) {
        int sz = s1.size();
        int i = 0, j = 0;
        int res = 0;

        while(i < sz) {
            j = i;
            while(s1[i] != s2[j]) j++;
            while(i < j) {
                swap(s2[j], s2[j - 1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1850.md" >}}
---
{{< youtube _83XSvgd_is >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1851: Minimum Interval to Include Each Query](https://grid47.xyz/posts/leetcode_1851) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

