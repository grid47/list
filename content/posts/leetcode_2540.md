
+++
authors = ["Crafted by Me"]
title = "Leetcode 2540: Minimum Common Value"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2540: Minimum Common Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-common-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int x: nums1)
            mp[x] = true;
        for(int y: nums2)
            if(mp.count(y))
                return y;
        return -1;
    }
};
{{< /highlight >}}


---
{{< youtube pbKnQYJuSY0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2541: Minimum Operations to Make Array Equal II](https://grid47.xyz/posts/leetcode_2541) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

