
+++
authors = ["grid47"]
title = "Leetcode 2841: Maximum Sum of Almost Unique Subarray"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2841: Maximum Sum of Almost Unique Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2841.md" >}}
---
{{< youtube L8BHtlpLCQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2843:   Count Symmetric Integers](https://grid47.xyz/leetcode/solution-2843-count-symmetric-integers/) |
| --- |
