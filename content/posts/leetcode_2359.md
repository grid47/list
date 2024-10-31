
+++
authors = ["Crafted by Me"]
title = "Leetcode 2359: Find Closest Node to Given Two Nodes"
date = "2018-05-18"
description = "Solution to Leetcode 2359"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    void dfs(int node, vector<int> &edge, vector<int> &vis, int x) {
        vis[node] = x;
        if(edge[node] != -1 && vis[edge[node]] == -1)
            dfs(edge[node], edge, vis, x + 1);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1);
        dfs(node1, edges, dist1, 0);
        vector<int> dist2(n, -1);
        dfs(node2, edges, dist2, 0);
        
        int dist, ans = -1, sol = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            else
                dist = max(dist1[i], dist2[i]);
            
            if(dist < sol) {
                sol = dist;
                ans = i;
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

