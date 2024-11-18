
+++
authors = ["grid47"]
title = "Leetcode 724: Find Pivot Index"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 724: Find Pivot Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "u89i60lYx8U"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-pivot-index/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/724.webp" 
    alt="A number array where the pivot index is found, with the pivot glowing brightly as it’s identified."
    caption="Solution to LeetCode 724: Find Pivot Index Problem"
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
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++) {
            right -= nums[i];
            if(right == left) return i;
            left  += nums[i];
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/724.md" >}}
---
{{< youtube u89i60lYx8U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #725: Split Linked List in Parts](https://grid47.xyz/leetcode/solution-725-split-linked-list-in-parts/) |
| --- |
