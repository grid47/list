
+++
authors = ["Crafted by Me"]
title = "Leetcode 1125: Smallest Sufficient Team"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1125: Smallest Sufficient Team in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-sufficient-team/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for(int i = 0; i < req.size(); i++)
            mp[req[i]] = i;
        
        int n = req.size();
        
        unordered_map<int, vector<int>> dp;        
        dp.reserve(1 << n);
        dp[0] = {};

        for(int i = 0; i < people.size(); i++) {
            int m = 0;
            for(string x: people[i]) {
                m |= (1 << mp[x]);
            }
            
            for(auto it = dp.begin(); it != dp.end(); it++) {
                int comb = m | it->first;
                if(!dp.count(comb) || (dp[comb].size() > 1 + dp[it->first].size())) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1125.md" >}}
---
{{< youtube yiAaGRWdqVA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1126: Active Businesses](https://grid47.xyz/posts/leetcode_1126) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

