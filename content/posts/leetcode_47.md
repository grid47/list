
+++
authors = ["Crafted by Me"]
title = "Leetcode 47: Permutations II"
date = "2024-09-16"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/47.md" >}}
---
{{< youtube qhBVWf0YafA >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

