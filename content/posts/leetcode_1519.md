
+++
authors = ["Crafted by Me"]
title = "Leetcode 1519: Number of Nodes in the Sub-Tree With the Same Label"
date = "2020-09-04"
description = "Solution to Leetcode 1519"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> ans;
    vector<int> vst;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 1);
        vst.resize(n, 0);
        vector<vector<int>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vst[0] = 1;
        dfs(n, 0, adj, labels);
        return ans;
    }

    vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
        vector<int> cnt(26, 0);
        for(auto v: adj[u]) {
            if(vst[v]) continue;

            vst[v] = 1;
            vector<int> sub = dfs(n, v, adj, labels);
            for(int i = 0; i < 26; i++)
                cnt[i] += sub[i];
        }

        cnt[labels[u] - 'a']++;
        ans[u] = cnt[labels[u] - 'a'];
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

