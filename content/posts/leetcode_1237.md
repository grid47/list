
+++
authors = ["Crafted by Me"]
title = "Leetcode 1237: Find Positive Integer Solution for a Given Equation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1237: Find Positive Integer Solution for a Given Equation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Binary Search","Interactive"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/)

---

**Code:**

{{< highlight cpp >}}
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int xl = 1, xr = 1000;

        vector<vector<int>> res;
        
        for(int x = 1; x <= 1000; x++) {
            if(cf.f(x, 0) > z) break;
            
            int ans = -1;
            int yl = 1, yr = 1000;            
            while(yl <= yr) {
                int ymid = yl + (yr - yl + 1) / 2;
                int sol = cf.f(x, ymid);
                if(sol == z) {
                    ans = ymid;
                    break;
                }
                if(sol < z) yl = ymid + 1;
                else        yr = ymid - 1;
            }
            if(ans != -1) res.push_back({x, ans});
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1237.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1238: Circular Permutation in Binary Representation](https://grid47.xyz/posts/leetcode_1238) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

