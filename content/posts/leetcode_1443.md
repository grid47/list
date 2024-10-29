
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1443: Minimum Time to Collect All Apples in a Tree"
date = "2020-11-17"
description = "Solution to Leetcode 1443"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

