
+++
authors = ["Crafted by Me"]
title = "Leetcode 1943: Describe the Painting"
date = "2019-07-09"
description = "In-depth solution and explanation for Leetcode 1943: Describe the Painting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/describe-the-painting/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segs) {
        
       // sort(seg.begin(), seg.end());
        
        map<ll, ll> mp;
        
        
        vector<vector<ll>> res;
        int n = segs.size();
        for(vector<int> seg : segs) {
            mp[seg[0]] += seg[2];
            mp[seg[1]] -= seg[2];
            
            
            }
        
        ll prv = -1, clr = 0;
        for(auto & itr : mp) {
            
            if(clr )
                res.push_back({prv, itr.first, clr});
            clr += itr.second;
            prv = itr.first;
            
            }
        
        return res;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #1944: Number of Visible People in a Queue](grid47.xyz/leetcode_1944) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

