
+++
authors = ["Crafted by Me"]
title = "Leetcode 870: Advantage Shuffle"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 870: Advantage Shuffle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/advantage-shuffle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(begin(nums1), end(nums1));
        for ( auto i = 0; i < nums2.size(); i++) {
            auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
            nums1[i] = *p;
            s.erase(p);
        }
        return nums1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/870.md" >}}
---
{{< youtube fY310tCXS_E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #871: Minimum Number of Refueling Stops](https://grid47.xyz/posts/leetcode_871) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

