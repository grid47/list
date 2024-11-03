
+++
authors = ["Crafted by Me"]
title = "Leetcode 2903: Find Indices With Index and Value Difference I"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2903: Find Indices With Index and Value Difference I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idif, int vdif) {

        int mn = 0, mx = 0;
        for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
            mn = nums[mn] < nums[j] ? mn : j;
            mx = nums[mx] > nums[j] ? mx : j;
            if (abs(nums[i] - nums[mn]) >= vdif)
                return {mn, i};
            if (abs(nums[i] - nums[mx]) >= vdif)
                return {mx, i};
        }
        return {-1, -1};        

    }
};
{{< /highlight >}}


---
{{< youtube R731s1mHVWM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2904: Shortest and Lexicographically Smallest Beautiful String](https://grid47.xyz/posts/leetcode_2904) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

