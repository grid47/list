
+++
authors = ["Crafted by Me"]
title = "Leetcode 2811: Check if it is Possible to Split Array"
date = "2017-02-21"
description = "In-depth solution and explanation for Leetcode 2811: Check if it is Possible to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] + nums[i + 1] >= m)
                return true;
        return nums.size() < 3;        
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2812: Find the Safest Path in a Grid](grid47.xyz/leetcode_2812) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

