
+++
authors = ["Crafted by Me"]
title = "Leetcode 2164: Sort Even and Odd Indices Independently"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2164: Sort Even and Odd Indices Independently in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2165: Smallest Value of the Rearranged Number](https://grid47.xyz/posts/leetcode_2165) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

