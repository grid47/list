
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1029: Two City Scheduling"
date = "2022-01-06"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

