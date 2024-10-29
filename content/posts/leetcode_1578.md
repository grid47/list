
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1578: Minimum Time to Make Rope Colorful"
date = "2020-07-05"
description = "Solution to Leetcode 1578"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int minCost(string colors, vector<int>& cost) {
        
        int res = 0, sum, mx;
        
        int i = 1, n = cost.size();
        
        while(i < n) {
            int e = i;
            sum = cost[e - 1];
            mx = cost[e - 1];
            
            while(e < n && colors[e] == colors[e-1]) {
                sum += cost[e];
                mx = max(mx, cost[e]);
                e++;
            }
            
            res += (sum-mx);
            
            i = e + 1;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

