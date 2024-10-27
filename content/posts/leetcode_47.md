
+++
authors = ["Yasir"]
title = "Leetcode 47: Permutations II"
date = "2024-09-11"
description = "Solution to Leetcode 47"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutations-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    void f(vector<int>&nums,vector<vector<int>>&ans,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,int>mp;
        for(int i=ind;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }else{
                mp[nums[i]]++;
                swap(nums[i],nums[ind]);
                f(nums,ans,ind+1);
                swap(nums[i],nums[ind]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,ans,0);
        return ans;
    }
};
{{< /highlight >}}

