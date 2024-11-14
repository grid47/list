
+++
authors = ["grid47"]
title = "Leetcode 795: Number of Subarrays with Bounded Maximum"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 795: Number of Subarrays with Bounded Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/795.webp" 
    alt="A sequence of numbers where subarrays are counted with a bounded maximum, glowing softly as each valid subarray is found."
    caption="Solution to LeetCode 795: Number of Subarrays with Bounded Maximum Problem"
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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n = nums.size();
        
        int ans = 0, dp = 0, prv = -1;
        for(int i = 0; i < n; i++) {
            
            if(nums[i] < left)
                ans += dp;
                
            if(nums[i] > right) {
                dp = 0;
                prv = i;
            }
                
            if(nums[i] >= left && nums[i] <= right) {
                dp = i - prv;
                ans += dp;
            }
                
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/795.md" >}}
---
{{< youtube V8jAp1Zi1Os >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #797: All Paths From Source to Target](https://grid47.xyz/posts/leetcode-797-all-paths-from-source-to-target-solution/) |
| --- |
