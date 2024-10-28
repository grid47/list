
+++
authors = ["Yasir"]
title = "Leetcode 1288: Remove Covered Intervals"
date = "2021-04-20"
description = "Solution to Leetcode 1288"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-covered-intervals/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int res = 0, left = -1, right = -1;
        
        for(auto p: ivl) {
            if(left < p[0] && right < p[1]) {
                res++;
                left = p[0];
            }
            right = max(p[1], right);
        }
        
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

