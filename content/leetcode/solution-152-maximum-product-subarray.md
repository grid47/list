
+++
authors = ["grid47"]
title = "Leetcode 152: Maximum Product Subarray"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 152: Maximum Product Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp"
youtube = "lXVy6YWFcRM"
youtube_upload_date="2021-01-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lXVy6YWFcRM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-subarray/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/152.webp" 
    alt="A radiant subarray of numbers, with the product of values glowing brightly as the maximum result."
    caption="Solution to LeetCode 152: Maximum Product Subarray Problem"
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
    int maxProduct(vector<int>& nums) {
        int mx = 1, mn = 1;

        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            
            res = max(res, mx);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/152.md" >}}
---
{{< youtube lXVy6YWFcRM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #153: Find Minimum in Rotated Sorted Array](https://grid47.xyz/leetcode/solution-153-find-minimum-in-rotated-sorted-array/) |
| --- |