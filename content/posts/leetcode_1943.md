
+++
authors = ["Crafted by Me"]
title = "Leetcode 1943: Describe the Painting"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1943: Describe the Painting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Prefix Sum"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1943.md" >}}
---
{{< youtube inJXN48LgPo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1944: Number of Visible People in a Queue](https://grid47.xyz/posts/leetcode_1944) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

