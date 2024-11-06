
+++
authors = ["Crafted by Me"]
title = "Leetcode 1818: Minimum Absolute Sum Difference"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1818: Minimum Absolute Sum Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-sum-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        set<int> sel(begin(nums1), end(nums1));

        long gain = 0, res = 0;
        for(int i = 0; i < n; i++) {
            long og = abs(nums1[i] - nums2[i]);
            res += og;
            if (gain < og) {
                auto num = sel.lower_bound(nums2[i]);
                if (num !=   end(sel)) gain = max(gain, og - abs(*num       - nums2[i]));
                if (num != begin(sel)) gain = max(gain, og - abs(*prev(num) - nums2[i]));
            }
        }

        return (res - gain) % 1000000007;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1818.md" >}}
---
{{< youtube PlenJ9Ny45s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1819: Number of Different Subsequences GCDs](https://grid47.xyz/posts/leetcode_1819) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

