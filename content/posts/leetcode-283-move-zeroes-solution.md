
+++
authors = ["grid47"]
title = "Leetcode 283: Move Zeroes"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 283: Move Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-zeroes/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/283.webp" 
    alt="A sequence where zeroes gently move to the end, and the remaining elements shift into place."
    caption="Solution to LeetCode 283: Move Zeroes Problem"
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
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[i], nums[j]), j++;
        }
        while(j < nums.size())
            nums[j++] = 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/283.md" >}}
---
{{< youtube 39VJV4KVyi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #287: Find the Duplicate Number](https://grid47.xyz/posts/leetcode-287-find-the-duplicate-number-solution/) |
| --- |
