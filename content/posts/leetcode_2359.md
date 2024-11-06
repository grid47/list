
+++
authors = ["Crafted by Me"]
title = "Leetcode 2359: Find Closest Node to Given Two Nodes"
date = "2024-11-01"
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


---
{{< youtube AZA8orksO4w >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2360: Longest Cycle in a Graph](https://grid47.xyz/posts/leetcode_2360) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

