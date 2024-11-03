
+++
authors = ["Crafted by Me"]
title = "Leetcode 2357: Make Array Zero by Subtracting Equal Amounts"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2357: Make Array Zero by Subtracting Equal Amounts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = 0, res = 0, diff;
        for(int i = 0; i < nums.size(); i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube rtGJycuTSUo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2358: Maximum Number of Groups Entering a Competition](https://grid47.xyz/posts/leetcode_2358) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

