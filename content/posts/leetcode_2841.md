
+++
authors = ["Crafted by Me"]
title = "Leetcode 2841: Maximum Sum of Almost Unique Subarray"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2841: Maximum Sum of Almost Unique Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxSum(vector<int>& nums, int size, int k) {
        unordered_map<int,int> m;
        long long sum=0;
        long long maxi=0;
        int i=0;
        int j=0;
        
        while(j<nums.size())
        {
            m[nums[j]]++;
            sum+=nums[j];
            
            if(j-i+1>k)
            {
                m[nums[i]]--;
                sum-=nums[i];
                    
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);    
                }
                
                i++;
            }
            
            
            
            if(j-i+1==k)
            {
                if(m.size() >= size)
                {
                    maxi=max(sum , maxi);
                    // cout<<maxi<<endl;
                }
            }
            
            j++;
        }
        
        return maxi;
    }
};
{{< /highlight >}}


---
{{< youtube L8BHtlpLCQw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2842: Count K-Subsequences of a String With Maximum Beauty](https://grid47.xyz/posts/leetcode_2842) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

