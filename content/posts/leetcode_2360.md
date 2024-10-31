
+++
authors = ["Crafted by Me"]
title = "Leetcode 2360: Longest Cycle in a Graph"
date = "2018-05-17"
description = "Solution to Leetcode 2360"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-cycle-in-a-graph/description/)

---

{{< youtube liPjCFmSpS4 >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int ans = -1;
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> vis(n, 0);        
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vector<int> store;
            dfs(i, vis, edges, store);
        }
        
        return ans; 
    }
    
    void dfs(int cur, vector<int> &vis, vector<int> &grid, vector<int> &store) {
        if(cur == -1) return;


        if(vis[cur]) {
            int pt = -1;

            for(int i = 0; i < store.size(); i++) {
                if(store[i] == cur) {
                    pt = i;
                    break;
                }
            }
            if(pt == -1) return;
            ans = max(ans, (int)store.size() - pt);
        } else {
        vis[cur] = true;            
            store.push_back(cur);
            dfs(grid[cur], vis, grid, store);
        }
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

