
+++
authors = ["grid47"]
title = "Leetcode 1443: Minimum Time to Collect All Apples in a Tree"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1443: Minimum Time to Collect All Apples in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, vector<int>> gph;
    map<int, int> visited;
    vector<bool> hasApple;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->hasApple = hasApple;
        for(auto x: edges) {
            gph[x[0]].push_back(x[1]);
            gph[x[1]].push_back(x[0]);
        }
        
        return dfs(0, 0);
    }
    
    int dfs(int mycost, int node) {
        if(visited[node]) return 0;
        visited[node] = true;
        int childcost = 0;
        for(int x: gph[node]) {
            childcost += dfs(2, x);
        }
        if(childcost == 0 && hasApple[node] == false)
            return 0;
        
        return childcost + mycost;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1443.md" >}}
---
{{< youtube Xdt5Z583auM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1444: Number of Ways of Cutting a Pizza](https://grid47.xyz/posts/leetcode-1444-number-of-ways-of-cutting-a-pizza-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}