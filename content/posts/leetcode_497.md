
+++
authors = ["Yasir"]
title = "Leetcode 497: Random Point in Non-overlapping Rectangles"
date = "2023-06-19"
description = "Solution to Leetcode 497"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    vector<int> v;
    vector<vector<int>> rect;
public:
    
    int area(vector<int> r) {
        
        return (r[2] - r[0] +1) * (r[3] - r[1] +1);
    }
    
    Solution(vector<vector<int>>& r) {
        rect = r;
        for(vector<int> re : r) {
            v.push_back(area(re) + (v.empty()? 0 : v.back()));
        }
    }
    
    vector<int> pick() {
        int d = rand() % v.back();
        int idz = upper_bound(v.begin(), v.end(), d) - v.begin();
        vector<int> r = rect[idz];
        return {
            rand() % (r[2] - r[0] +1) + r[0],
            rand() % (r[3] - r[1] +1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
{{< /highlight >}}

