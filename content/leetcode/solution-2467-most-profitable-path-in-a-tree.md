
+++
authors = ["grid47"]
title = "Leetcode 2467: Most Profitable Path in a Tree"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2467: Most Profitable Path in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Tree","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MCp9k0kKQqc"
youtube_upload_date="2022-11-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MCp9k0kKQqc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/most-profitable-path-in-a-tree/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> par, dis;
    
    void dfs(int u, int p = 0, int d = 0) {
        dis[u] = d;
        par[u] = p;
        for(int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d +1);
        }
    }
    
     
    int dfs2(int u,vector<int>&amount,int p= 0){

        int ret = amount[u];

        int mxc = -INT_MAX;

        for(int v:adj[u]){

            if(v!=p){

                mxc= max(mxc,dfs2(v,amount,u));

            }

        }

		//if the node is leaf we just return its amount

        if(mxc==-INT_MAX)return ret;

        else return ret+mxc;

    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int cur = bob;
        int bob_dis = 0;
		//update the path of from Bob to 0
        while(cur!=0){
            if(dis[cur]>bob_dis){
                amount[cur] = 0;
            }else if(dis[cur]==bob_dis){
                amount[cur]/=2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0,amount);
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2467.md" >}}
---
{{< youtube MCp9k0kKQqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2469: Convert the Temperature](https://grid47.xyz/leetcode/solution-2469-convert-the-temperature/) |
| --- |
