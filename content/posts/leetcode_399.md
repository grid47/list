
+++
authors = ["Crafted by Me"]
title = "Leetcode 399: Evaluate Division"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 399: Evaluate Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Depth-First Search","Breadth-First Search","Union Find","Graph","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-division/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqn, vector<double>& val, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> graph;
        
        for(int i = 0; i < eqn.size(); i++) {
            double w = val[i];
            graph[eqn[i][0]].push_back(make_pair(eqn[i][1], w));
            if (w == 0) continue;
            graph[eqn[i][1]].push_back(make_pair(eqn[i][0], 1 / w));
        }
        
        vector<double> ans;
        
        for(int i = 0; i < q.size(); i++) {
            set<string> vis;
            double res = dfs(q[i][0], q[i][1], vis, graph);
            if(res < 0) res = -1;
            ans.push_back(res);
        }
        return ans;
    }
    
    double dfs(string start, string end, set<string> &vis, map<string, vector<pair<string, double>>> &gph) {
        
        if(start == end) return gph.count(start)? 1: -1;
        vis.insert(start);
        double ans = -1;
        for(pair<string, double> x: gph[start]) {
            if(vis.count(x.first)) continue;

            double res = x.second * dfs(x.first, end, vis, gph);
            if(res < 0) continue;
            return res;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/399.md" >}}
---
{{< youtube B5uvxUfQxN4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #400: Nth Digit](https://grid47.xyz/posts/leetcode_400) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

