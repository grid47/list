
+++
authors = ["Crafted by Me"]
title = "Leetcode 540: Single Element in a Sorted Array"
date = "2023-05-12"
description = "In-depth solution and explanation for Leetcode 540: Single Element in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res =0;
        for(int num : nums)
        res ^= num;

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/540.md" >}}
---
{{< youtube T4nRgIxka18 >}}
| Next : [LeetCode #541: Reverse String II](https://grid47.xyz/posts/leetcode_541) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

