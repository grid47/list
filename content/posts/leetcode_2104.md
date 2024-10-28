
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2104: Sum of Subarray Ranges"
date = "2019-01-25"
description = "Solution to Leetcode 2104"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subarray-ranges/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res = 0, n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            int mini = nums[i], maxi = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                res += maxi - mini;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

