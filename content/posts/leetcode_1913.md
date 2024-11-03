
+++
authors = ["Crafted by Me"]
title = "Leetcode 1913: Maximum Product Difference Between Two Pairs"
date = "2019-08-08"
description = "In-depth solution and explanation for Leetcode 1913: Maximum Product Difference Between Two Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 1914: Cyclically Rotating a Grid |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

