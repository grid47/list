
+++
authors = ["grid47"]
title = "Leetcode 1311: Get Watched Videos by Your Friends"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1311: Get Watched Videos by Your Friends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Breadth-First Search","Graph","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1314: Matrix Block Sum](https://grid47.xyz/leetcode/solution-1314-matrix-block-sum/) |
| --- |
