
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 134: Gas Station"
date = "2024-06-18"
description = "Solution to Leetcode 134"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/gas-station/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int net = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i];
            net += cost[i];
        }
        if (net > tank) return -1;
        
        tank = 0;
        int res = -1;
        
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i];
            tank -= cost[i];
            if(tank < 0) {
                tank = 0;
                res = i;
            }
        }
        return res + 1;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/134.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
