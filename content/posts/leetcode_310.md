
+++
authors = ["Crafted by Me"]
title = "Leetcode 310: Minimum Height Trees"
date = "2023-12-28"
description = "In-depth solution and explanation for Leetcode 310: Minimum Height Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-height-trees/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(degree[i] == 1)
                q.push(i);
        
        vector<int> res;
        
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                res.push_back(tmp);
                for(auto nbr: adj[tmp]) {
                    degree[nbr]--;
                    if(degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/310.md" >}}
---

| Next : [LeetCode #311: Sparse Matrix Multiplication](https://grid47.xyz/posts/leetcode_311) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

