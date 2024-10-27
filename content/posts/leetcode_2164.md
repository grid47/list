
+++
authors = ["Yasir"]
title = "Leetcode 2164: Sort Even and Odd Indices Independently"
date = "2018-11-25"
description = "Solution to Leetcode 2164"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int minIndex;
// Here in this nested loop , we are sorting the elements at even indices in non-decreasing order.
        for(int i=0;i<nums.size();i+=2)
        {
            minIndex=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]<nums[minIndex])
                    minIndex=j;
            }
            swap(nums[i],nums[minIndex]);
        }
// Here , we are trying to sort the elements at odd indices in non-increasing order. 
        for(int i=1;i<nums.size();i+=2)
        {
            minIndex=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]>nums[minIndex])
                    minIndex=j;
            }
            swap(nums[i],nums[minIndex]);
        }
        
        return nums;
    }
};
{{< /highlight >}}

