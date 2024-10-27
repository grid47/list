
+++
authors = ["Yasir"]
title = "Leetcode 2908: Minimum Sum of Mountain Triplets I"
date = "2016-11-11"
description = "Solution to Leetcode 2908"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] < nums[j] && nums[k] < nums[j]) ans = min(ans,nums[i]+nums[j]+nums[k]);
                }
            }
        }
        
        return (ans==INT_MAX ? -1:ans);
    }
};
{{< /highlight >}}

