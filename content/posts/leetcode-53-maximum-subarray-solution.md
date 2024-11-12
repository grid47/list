
+++
authors = ["grid47"]
title = "Leetcode 53: Maximum Subarray"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 53: Maximum Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subarray/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/53.webp" 
    alt="A bright, uplifting wave rising, showing the peak of a series of numbers."
    caption="Solution to LeetCode 53: Maximum Subarray Problem"
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
    int maxSubArray(vector<int>& nums) {
        int l = nums[0], g = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > l + nums[i])
                l = nums[i];
            else l += nums[i];
            
            g = max(g, l);
        }
        return g;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/53.md" >}}
---
{{< youtube 5WZl3MMT0Eg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #54: Spiral Matrix](https://grid47.xyz/posts/leetcode-54-spiral-matrix-solution/) |
| --- |
