
+++
authors = ["grid47"]
title = "Leetcode 939: Minimum Area Rectangle"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 939: Minimum Area Rectangle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Geometry","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-area-rectangle/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAreaRect(vector<vector<int>>& pts) {
        
        unordered_map<int, set<int>> mp;
        for(auto &it: pts)
        mp[it[0]].insert(it[1]);
        
        int n = pts.size();
        int area = INT_MAX;
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            
            int x1 = pts[i][0], y1 = pts[i][1];
            int x2 = pts[j][0], y2 = pts[j][1];
            
            if(x1 != x2 && y1 != y2) {
                
                if(mp[x1].find(y2) != mp[x1].end() &&
                  mp[x2].find(y1) != mp[x2].end())
                {
                    area = min(area, abs(x1 - x2) * abs(y1 - y2));
                }
            }
            
        }
        
        return area == INT_MAX? 0: area;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/939.md" >}}
---
{{< youtube pFgBZFKJ2Co >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #940: Distinct Subsequences II](https://grid47.xyz/posts/leetcode-940-distinct-subsequences-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
