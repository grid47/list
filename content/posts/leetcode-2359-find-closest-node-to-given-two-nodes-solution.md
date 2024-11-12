
+++
authors = ["grid47"]
title = "Leetcode 2359: Find Closest Node to Given Two Nodes"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2359: Find Closest Node to Given Two Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Graph"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2359.md" >}}
---
{{< youtube AZA8orksO4w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2363: Merge Similar Items](https://grid47.xyz/posts/leetcode-2363-merge-similar-items-solution/) |
| --- |
