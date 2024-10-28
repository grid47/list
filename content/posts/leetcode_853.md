
+++
authors = ["Yasir"]
title = "Leetcode 853: Car Fleet"
date = "2022-06-29"
description = "Solution to Leetcode 853"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/car-fleet/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& v) {
        map<int, double> t;
        for(int i = 0; i < pos.size(); i++) {
            t[-pos[i]] = (double) (target-pos[i]) / v[i];
        }
        
        int fleet = 0;
        double cur = 0;
        
        for(auto it: t) {
            if(it.second > cur) fleet++, cur = it.second;
        }
        return fleet;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

