
+++
authors = ["Yasir"]
title = "Leetcode 1029: Two City Scheduling"
date = "2022-01-03"
description = "Solution to Leetcode 1029"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/two-city-scheduling/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
        
        2n people - interview
        
        
        */
        int mc = 0;
        vector<int> refund;
        
        for(auto c : costs) {
            mc += c[0];
            refund.push_back(c[1] - c[0]);
        }
        sort(refund.begin(), refund.end());
        int n = costs.size()/ 2;
        
        for(int i = 0; i < n; i++) {
            mc += refund[i];
        }
        
        return mc;
    }
};
{{< /highlight >}}

