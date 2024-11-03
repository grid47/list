
+++
authors = ["Crafted by Me"]
title = "Leetcode 2642: Design Graph With Shortest Path Calculator"
date = "2017-08-09"
description = "In-depth solution and explanation for Leetcode 2642: Design Graph With Shortest Path Calculator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/)

---

**Code:**

{{< highlight cpp >}}
class Graph {
public:
    int n;
    vector<vector<pair<int, int>>> grid;
    
    int diji(int n1, int n2) {
        
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n1});
        dis[n1] = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            for(auto x: grid[node]) {
                int nxt = x.first;
                int w = x.second;
                if(dis[node] + w < dis[nxt]) {
                    dis[nxt] = dis[node] + w;
                    pq.push({dis[nxt], nxt});
                }
            }
        }
        
        if(dis[n2] == INT_MAX) return -1;
        
        return dis[n2];
        
    }
    
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        grid.resize(n);
        for(auto e: edges) {
            grid[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
            grid[e[0]].push_back({e[1], e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return diji(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
{{< /highlight >}}


---

| Next : [LeetCode #2643: Row With Maximum Ones](https://grid47.xyz/posts/leetcode_2643) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

