
+++
authors = ["Crafted by Me"]
title = "Leetcode 1971: Find if Path Exists in Graph"
date = "2018-06-10"
description = "Solution to Leetcode 1971"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-if-path-exists-in-graph/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == end)
                return 1; 
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};
{{< /highlight >}}


---
{{< youtube knLFe7hEp3Y >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

