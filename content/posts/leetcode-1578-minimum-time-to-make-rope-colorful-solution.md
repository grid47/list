
+++
authors = ["grid47"]
title = "Leetcode 1578: Minimum Time to Make Rope Colorful"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1578: Minimum Time to Make Rope Colorful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming","Greedy"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1578.md" >}}
---
{{< youtube 9_9jwd2DHMU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1582: Special Positions in a Binary Matrix](https://grid47.xyz/posts/leetcode-1582-special-positions-in-a-binary-matrix-solution/) |
| --- |
