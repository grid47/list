
+++
authors = ["Crafted by Me"]
title = "Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three"
date = "2016-02-08"
description = "In-depth solution and explanation for Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #3191: Minimum Operations to Make Binary Array Elements Equal to One I](https://grid47.xyz/posts/leetcode_3191) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

