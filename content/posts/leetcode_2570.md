
+++
authors = ["Yasir"]
title = "Leetcode 2570: Merge Two 2D Arrays by Summing Values"
date = "2017-10-15"
description = "Solution to Leetcode 2570"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        for(auto& itr : nums1){
            m[itr[0]] += itr[1]; 
        }
        for(auto& itr : nums2){
            m[itr[0]] += itr[1]; 
        }
        vector<vector<int> > v;
        for(auto& itr : m){
            v.push_back({itr.first,itr.second});
        }
        return v;
    }
};
{{< /highlight >}}

