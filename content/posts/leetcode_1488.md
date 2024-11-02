
+++
authors = ["Crafted by Me"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2019-10-06"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

