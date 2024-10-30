
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 853: Car Fleet"
date = "2022-07-01"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/853.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

