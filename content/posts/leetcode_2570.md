
+++
authors = ["Crafted by Me"]
title = "Leetcode 2570: Merge Two 2D Arrays by Summing Values"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2570: Merge Two 2D Arrays by Summing Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
{{< youtube Ou0KdT0OgV8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2571: Minimum Operations to Reduce an Integer to 0](https://grid47.xyz/posts/leetcode_2571) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

