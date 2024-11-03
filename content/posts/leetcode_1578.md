
+++
authors = ["Crafted by Me"]
title = "Leetcode 1578: Minimum Time to Make Rope Colorful"
date = "2020-07-08"
description = "In-depth solution and explanation for Leetcode 1578: Minimum Time to Make Rope Colorful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

