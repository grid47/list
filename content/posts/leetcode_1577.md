
+++
authors = ["Crafted by Me"]
title = "Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        long res = 0;

        for(int v: nums1)
            res += twoProd((long)v * v, nums2);
        for(int v: nums2)
            res += twoProd((long)v * v, nums1);

        return res;
    }
    
    
    long twoProd(long i, vector<int> &nums) {
        map<long, long> mp;
        
        int cnt = 0;
        for(int n : nums) {
            if(i % n == 0)
                cnt += mp[i / n];
            mp[n]++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1577.md" >}}
---
{{< youtube ZNAJbQTv3yk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1578: Minimum Time to Make Rope Colorful](https://grid47.xyz/posts/leetcode_1578) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

