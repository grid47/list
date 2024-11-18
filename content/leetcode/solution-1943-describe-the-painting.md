
+++
authors = ["grid47"]
title = "Leetcode 1943: Describe the Painting"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1943: Describe the Painting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "inJXN48LgPo"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1945: Sum of Digits of String After Convert](https://grid47.xyz/leetcode/solution-1945-sum-of-digits-of-string-after-convert/) |
| --- |
