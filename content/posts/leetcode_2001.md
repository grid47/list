
+++
authors = ["Yasir"]
title = "Leetcode 2001: Number of Pairs of Interchangeable Rectangles"
date = "2019-05-07"
description = "Solution to Leetcode 2001"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long cnt = 0;
        for(auto r: rectangles) {
            double x = (double)r[0]/ r[1];
            if(mp.find(x) != mp.end()) cnt += mp[x];
            mp[x]++;
        }

        // int cnt = 0;
        // for(auto &it: mp) 
        // {
            // cout << it.second << ' ';
            // cnt = cnt + it.second * (it.second -1 ) / 2;
        // }

        return cnt;
    }
};
{{< /highlight >}}

