
+++
authors = ["grid47"]
title = "Leetcode 2570: Merge Two 2D Arrays by Summing Values"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2570: Merge Two 2D Arrays by Summing Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "Ou0KdT0OgV8"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2570.md" >}}
---
{{< youtube Ou0KdT0OgV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2571: Minimum Operations to Reduce an Integer to 0](https://grid47.xyz/leetcode/solution-2571-minimum-operations-to-reduce-an-integer-to-0/) |
| --- |
