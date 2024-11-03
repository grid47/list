
+++
authors = ["Crafted by Me"]
title = "Leetcode 721: Accounts Merge"
date = "2022-11-12"
description = "In-depth solution and explanation for Leetcode 721: Accounts Merge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/accounts-merge/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        map<string, string> mp;
        map<string, set<string>> gph;
        for(auto ac: acc) {
            for(int i = 1; i < ac.size(); i++) {
                mp[ac[i]] = ac[0];
                gph[ac[i]].insert(ac[1]);
                gph[ac[1]].insert(ac[i]);
            }
        }
        
        set<string> seen;
        vector<vector<string>> ans;
        for(auto it: mp) {
            if(seen.count(it.first)) continue;
            vector<string> tmp;
            dfs(tmp, gph, seen, it.first);
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), it.second);
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    void dfs(vector<string> &tmp, map<string, set<string>> &gph, set<string> &seen, string node) {
        tmp.push_back(node);
        seen.insert(node);
        for(auto it: gph[node]) {
            if(!seen.count(it)) {
                dfs(tmp, gph, seen, it);
            }
        }
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/721.md" >}}
---
{{< youtube otzKJY8YhRg >}}
| Next : [LeetCode #722: Remove Comments](https://grid47.xyz/posts/leetcode_722) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

