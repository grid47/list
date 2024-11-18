
+++
authors = ["grid47"]
title = "Leetcode 1701: Average Waiting Time"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1701: Average Waiting Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/average-waiting-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        
        int cur = cust[0][0];
        
        double n = cust.size();
        double sum = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(cur > cust[i][0])
            cur += cust[i][1];
            else
            cur = cust[i][0] + cust[i][1];
            
            sum += cur - cust[i][0];
            
        }
        
        return sum / n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1701.md" >}}
---
{{< youtube 2fN7uIgCIBA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1702: Maximum Binary String After Change](https://grid47.xyz/leetcode/solution-1702-maximum-binary-string-after-change/) |
| --- |
