
+++
authors = ["grid47"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2024-06-11"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1491: Average Salary Excluding the Minimum and Maximum Salary](https://grid47.xyz/leetcode/solution-1491-average-salary-excluding-the-minimum-and-maximum-salary/) |
| --- |
