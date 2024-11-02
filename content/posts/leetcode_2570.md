
+++
authors = ["Crafted by Me"]
title = "Leetcode 2570: Merge Two 2D Arrays by Summing Values"
date = "2016-10-19"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

