
+++
authors = ["Crafted by Me"]
title = "Leetcode 713: Subarray Product Less Than K"
date = "2022-11-20"
description = "In-depth solution and explanation for Leetcode 713: Subarray Product Less Than K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-product-less-than-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        long long prod = 1;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            
            while(prod >= k && j <= i) {
                prod /= nums[j++];
            }
            
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/713.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #714: Best Time to Buy and Sell Stock with Transaction Fee](https://grid47.xyz/posts/leetcode_714) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

