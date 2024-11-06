
+++
authors = ["Crafted by Me"]
title = "Leetcode 1376: Time Needed to Inform All Employees"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1376: Time Needed to Inform All Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int, vector<int>> gph;
        for(int i = 0; i < manager.size(); i++)
        gph[manager[i]].push_back(i);
        
        return dfs(headID, gph, informTime);
    }
    
    int dfs(int cur, map<int, vector<int>> &gph, vector<int> &it) {
        if(!gph.count(cur)) return 0;
        
        int mx = 0;
        for(auto x: gph[cur])
            mx = max(mx, dfs(x, gph, it));
        
        return mx + it[cur];
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1376.md" >}}
---
{{< youtube d0xAcl58SXg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1377: Frog Position After T Seconds](https://grid47.xyz/posts/leetcode_1377) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

