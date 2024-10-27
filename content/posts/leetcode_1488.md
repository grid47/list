
+++
authors = ["Yasir"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2020-10-01"
description = "Solution to Leetcode 1488"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/avoid-flood-in-the-city/description/)

---

**Code:**

{{< highlight html >}}
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

