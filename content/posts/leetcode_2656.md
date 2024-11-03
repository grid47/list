
+++
authors = ["Crafted by Me"]
title = "Leetcode 2656: Maximum Sum With Exactly K Elements "
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2656: Maximum Sum With Exactly K Elements  in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(), nums.end());
        return i * k + k * (k - 1) / 2;
    }
};
{{< /highlight >}}


---
{{< youtube lA9B6M4E_BQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2657: Find the Prefix Common Array of Two Arrays](https://grid47.xyz/posts/leetcode_2657) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

