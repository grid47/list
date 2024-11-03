
+++
authors = ["Crafted by Me"]
title = "Leetcode 2581: Count Number of Possible Root Nodes"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2581: Count Number of Possible Root Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-possible-root-nodes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> grid;
    vector<set<int>> guess;
    vector<int> par;
    int ans = 0, k;

    void fill_par(int node, int dad) {
        par[node] = dad;
        for(int it: grid[node]) {
            if(it != dad) fill_par(it, node);
        }
    }
    
    void dfs(int node, int dad, int cnt) {
        if(guess[node].count(dad)) cnt++;
        if(guess[dad].count(node)) cnt--;
        if(cnt >= k) ans++;
        for(int x: grid[node]) {
            if(x != dad) dfs(x, node, cnt);
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        int n = edges.size() + 1;
        grid.resize(n);
        for(auto e: edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);            
        }
        guess.resize(n);
        for(auto g: guesses) {
            guess[g[0]].insert(g[1]);
        }
        par.resize(n, 0);
        int cnt = 0;
        fill_par(0, -1);
        for(int i = 1; i < n; i++) {
            int dad = par[i];
            if(guess[dad].count(i)) cnt++;
        }
        if(cnt >= k) ans++;
        for(int x: grid[0]) dfs(x, 0, cnt);
        return ans;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2582: Pass the Pillow](https://grid47.xyz/posts/leetcode_2582) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

