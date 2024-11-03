
+++
authors = ["Crafted by Me"]
title = "Leetcode 1802: Maximum Value at a Given Index in a Bounded Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1802: Maximum Value at a Given Index in a Bounded Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(long long pk, long long n, long long i, long long sum) {
        sum -= n;
        long j = n - i - 1;
        
    long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
        
        return sum - need >= 0;
    }
    
    int maxValue(int n, int index, int mx) {
        
        int ans = 0, l = 0, r = mx;
        
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
            // cout << mid << " ";
            if(can(mid, n, index, mx)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        
        return ans + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1802.md" >}}
---
{{< youtube o3H1ccp2ckc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1803: Count Pairs With XOR in a Range](https://grid47.xyz/posts/leetcode_1803) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

