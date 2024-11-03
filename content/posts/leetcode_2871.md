
+++
authors = ["Crafted by Me"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2016-12-23"
description = "In-depth solution and explanation for Leetcode 2871: Split Array Into Maximum Number of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int n : nums) {
            cur = cur == 0 ? n : cur & n;
            res += cur == 0;
        }
        return max(1, res);
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2872: Maximum Number of K-Divisible Components](grid47.xyz/leetcode_2872) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

