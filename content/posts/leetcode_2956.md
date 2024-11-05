
+++
authors = ["Crafted by Me"]
title = "Leetcode 2956: Find Common Elements Between Two Arrays"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2956: Find Common Elements Between Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-common-elements-between-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1, n2;
        for(int x: nums1) n1.insert(x);
        for(int x: nums2) n2.insert(x);
        int cnt1 = 0;
        for(int x: nums1) if(n2.count(x)) cnt1++;
        int cnt2 = 0;
        for(int x: nums2) if(n1.count(x)) cnt2++;        
        return vector<int>{cnt1, cnt2};
    }
};
{{< /highlight >}}


---
{{< youtube jb1IbKe3bPE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2957: Remove Adjacent Almost-Equal Characters](https://grid47.xyz/posts/leetcode_2957) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

