
+++
authors = ["grid47"]
title = "Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "RdxsvhrTQ0A"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> dag(n);
        vector<vector<int>> grid(n), sol(n);
        vector<int> inward(n, 0);
        for(auto it: edges) {
            grid[it[0]].push_back(it[1]);
            inward[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(inward[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                for(auto it: grid[tmp]) {
                    inward[it]--;
                    dag[it].insert(tmp);
                    for(int x: dag[tmp])
                        dag[it].insert(x);
                    if(inward[it] == 0)
                        q.push(it);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(auto it: dag[i]) {
                sol[i].push_back(it);
            }
        }
        return sol;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2192.md" >}}
---
{{< youtube RdxsvhrTQ0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2194: Cells in a Range on an Excel Sheet](https://grid47.xyz/leetcode/solution-2194-cells-in-a-range-on-an-excel-sheet/) |
| --- |
