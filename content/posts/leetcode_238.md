
+++
authors = ["Crafted by Me"]
title = "Leetcode 238: Product of Array Except Self"
date = "2024-03-09"
description = "In-depth solution and explanation for Leetcode 238: Product of Array Except Self in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/product-of-array-except-self/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1), suf(n, 1);
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] * nums[i];
        for(int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] * nums[i];
        
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++)
            ans[i] = (i > 0? pre[i - 1]: 1) * (i < n - 1? suf[i + 1]: 1);
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/238.md" >}}
---
{{< youtube yKZFurr4GQA >}}
| Next : [LeetCode #239: Sliding Window Maximum](https://grid47.xyz/posts/leetcode_239) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

