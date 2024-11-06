
+++
authors = ["Crafted by Me"]
title = "Leetcode 1913: Maximum Product Difference Between Two Pairs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1913: Maximum Product Difference Between Two Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1914: Cyclically Rotating a Grid](https://grid47.xyz/posts/leetcode_1914) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
