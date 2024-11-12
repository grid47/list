
+++
authors = ["grid47"]
title = "Leetcode 238: Product of Array Except Self"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 238: Product of Array Except Self in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/product-of-array-except-self/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/238.webp" 
    alt="A sequence of glowing numbers representing the product of elements except the current one, showing a smooth transition"
    caption="Solution to LeetCode 238: Product of Array Except Self Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #242: Valid Anagram](https://grid47.xyz/posts/leetcode-242-valid-anagram-solution/) |
| --- |
