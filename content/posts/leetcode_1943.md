
+++
authors = ["Crafted by Me"]
title = "Leetcode 1943: Describe the Painting"
date = "2019-07-08"
description = "Solution to Leetcode 1943"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

