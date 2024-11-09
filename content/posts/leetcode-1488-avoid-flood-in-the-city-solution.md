
+++
authors = ["grid47"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1488: Avoid Flood in The City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/avoid-flood-in-the-city/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> dry;
        unordered_map<int, int> mp;
        
        int n = rains.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                dry.insert(i);
                ans.push_back(1);
            } else {
                int lake = rains[i];
                
                if(mp.count(lake)) {
                    
                    auto it = dry.lower_bound(mp[lake]);
                    if(it == dry.end()) return {};
                    
                    ans[*it] = lake;
                    dry.erase(*it);
                }
                mp[lake] = i;
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1488.md" >}}
---
{{< youtube EcvhHoFaDoU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1489: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://grid47.xyz/posts/leetcode-1488-avoid-flood-in-the-city-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
