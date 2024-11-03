
+++
authors = ["Crafted by Me"]
title = "Leetcode 1311: Get Watched Videos by Your Friends"
date = "2021-04-01"
description = "In-depth solution and explanation for Leetcode 1311: Get Watched Videos by Your Friends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/get-watched-videos-by-your-friends/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
        
    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int k) {
        
        int n = f.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(id);
        vis[id] = true;
        
        while(k--) {
            int sz = q.size();
            while(sz--) {
                int top = q.front();
                q.pop();
                for(auto it: f[top]) {
                    if(!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        
        map<string, int> mp;
        while(!q.empty()) {
            int fr = q.front();
            q.pop();
            for(string x: wv[fr]) {
                mp[x]++;
            }
        }
        
        vector<pair<int, string>> ans;
        for(auto it: mp) {
            ans.push_back({it.second, it.first});
        }

        sort(ans.begin(), ans.end());
     
        vector<string> res;
        for(auto it: ans)
            res.push_back(it.second);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1311.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

