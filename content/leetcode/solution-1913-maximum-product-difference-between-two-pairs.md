
+++
authors = ["grid47"]
title = "Leetcode 1913: Maximum Product Difference Between Two Pairs"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1913: Maximum Product Difference Between Two Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wBPoEm3r3EA"
youtube_upload_date="2023-12-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wBPoEm3r3EA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //we have to return the result of
        // (firstMax*secondMax) - (firstMin*secondMin)
        int max1=INT_MIN;
        int max2=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]>max1)
            {
                //assign the second max to max2
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2)
            {
                //it can become second max
                max2= nums[i];
            }
            
            //check for the minimum
            if(nums[i]<min1)
            {
                //it can become first minimum
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2)
            {
                //it can become second minimum
                min2=nums[i];
            }
        }
        return (max1*max2)- (min1*min2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1913.md" >}}
---
{{< youtube wBPoEm3r3EA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1914: Cyclically Rotating a Grid](https://grid47.xyz/leetcode/solution-1914-cyclically-rotating-a-grid/) |
| --- |