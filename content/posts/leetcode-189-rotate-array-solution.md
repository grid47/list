
+++
authors = ["grid47"]
title = "Leetcode 189: Rotate Array"
date = "2024-10-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 189: Rotate Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotate-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/189.webp" 
    alt="An array gently rotating, with the elements shifting in a calming, circular motion."
    caption="Solution to LeetCode 189: Rotate Array Problem"
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
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        rev(nums, 0, nums.size() - 1);
        rev(nums, 0, k - 1);
        rev(nums, k, nums.size() - 1);
        
    }
    
    void rev(vector<int>& nums, int i, int j) {
        while(i <= j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/189.md" >}}
---
{{< youtube lTHTR_jsqAQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #190: Reverse Bits](https://grid47.xyz/posts/leetcode-190-reverse-bits-solution/) |
| --- |
