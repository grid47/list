
+++
authors = ["Yasir"]
title = "Leetcode 2176: Count Equal and Divisible Pairs in an Array"
date = "2018-11-13"
description = "Solution to Leetcode 2176"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> umap;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(umap.find(nums[i]) != umap.end()) 
            {
                for(auto x : umap[nums[i]]) 
                    if((i * x) % k == 0)
                        count++;
            }
            
            umap[nums[i]].push_back(i);
        }
        return count;
    }
};
{{< /highlight >}}

