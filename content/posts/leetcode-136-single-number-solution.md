
+++
authors = ["grid47"]
title = "Leetcode 136: Single Number"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 136: Single Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/136.webp" 
    alt="A glowing, solitary number standing out in a sequence, signifying its uniqueness."
    caption="Solution to LeetCode 136: Single Number Problem"
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
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y: nums)
            x ^= y;
        return x;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/136.md" >}}
---
{{< youtube mriHA5vEh0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #137: Single Number II](https://grid47.xyz/posts/leetcode-137-single-number-ii-solution/) |
| --- |
