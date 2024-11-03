
+++
authors = ["Crafted by Me"]
title = "Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph"
date = "2018-11-02"
description = "In-depth solution and explanation for Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

