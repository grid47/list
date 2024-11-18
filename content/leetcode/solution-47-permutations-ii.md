
+++
authors = ["grid47"]
title = "Leetcode 47: Permutations II"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 47: Permutations II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "qhBVWf0YafA"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/47.webp"
+++



[`Problem Link`](https://leetcode.com/problems/permutations-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/47.webp" 
    alt="A similar sequence with a touch more complexity, glowing in multiple variations."
    caption="Solution to LeetCode 47: Permutations II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #48: Rotate Image](https://grid47.xyz/leetcode/solution-48-rotate-image/) |
| --- |
