
+++
authors = ["Crafted by Me"]
title = "Leetcode 1237: Find Positive Integer Solution for a Given Equation"
date = "2020-06-13"
description = "Solution to Leetcode 1237"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/description/)

---

**Code:**

{{< highlight cpp >}}
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int xl = 1, xr = 1000;

        vector<vector<int>> res;
        
        for(int x = 1; x <= 1000; x++) {
            if(cf.f(x, 0) > z) break;
            
            int ans = -1;
            int yl = 1, yr = 1000;            
            while(yl <= yr) {
                int ymid = yl + (yr - yl + 1) / 2;
                int sol = cf.f(x, ymid);
                if(sol == z) {
                    ans = ymid;
                    break;
                }
                if(sol < z) yl = ymid + 1;
                else        yr = ymid - 1;
            }
            if(ans != -1) res.push_back({x, ans});
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

