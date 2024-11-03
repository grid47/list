
+++
authors = ["Crafted by Me"]
title = "Leetcode 268: Missing Number"
date = "2024-02-08"
description = "In-depth solution and explanation for Leetcode 268: Missing Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/missing-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum ^= nums[i];
        for(int i = 0; i <= nums.size(); i++)
            sum ^= i;
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/268.md" >}}
---
{{< youtube WnPLSRLSANE >}}
| Next : [LeetCode #269: Alien Dictionary](https://grid47.xyz/posts/leetcode_269) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

