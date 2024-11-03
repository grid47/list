
+++
authors = ["Crafted by Me"]
title = "Leetcode 1887: Reduction Operations to Make the Array Elements Equal"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1887: Reduction Operations to Make the Array Elements Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        int ops = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; i--) {
            
            if(nums[i] == nums[i + 1]) continue;
            ops += (n - 1 - i);
            
        }
        
        return ops;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1887.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1888: Minimum Number of Flips to Make the Binary String Alternating](https://grid47.xyz/posts/leetcode_1888) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

