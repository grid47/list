
+++
authors = ["Crafted by Me"]
title = "Leetcode 827: Making A Large Island"
date = "2022-07-29"
description = "In-depth solution and explanation for Leetcode 827: Making A Large Island in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/making-a-large-island/description/)

---

**Code:**

{{< highlight cpp >}}
class uf {
    public:
    vector<int> par, sz;
    uf(int n) {
        par.resize(n);
        sz.resize(n, 1);        
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p != q) {
            if(sz[p] < sz[q]) {
                par[p] = q;
                sz[q] += sz[p];
            } else {
                par[q] = p;
                sz[p] += sz[q];                
            }
            return true;
        }
        return false;
    }
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);        
    }
    int size(int x) {
        int y = find(x);
        return sz[y];
    }
};


class Solution {
public:
    uf* UF;
    void dfs(vector<vector<int>>& grid, int i, int j, int p, vector<vector<int>>& vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        UF->join(j + i * grid.size(), p);
        dfs(grid, i + 1, j, p, vis);
        dfs(grid, i, j + 1, p, vis);
        dfs(grid, i - 1, j, p, vis);
        dfs(grid, i, j - 1, p, vis);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        UF = new uf(n * n);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1 && vis[i][j] == 0)
                dfs(grid, i, j, i * n+ j, vis);
        
        int mx = 0, ch = false;
        for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 0) {
                ch = true;
                int tmp = 0;
                set<int> par;
                if(i > 0 && grid[i - 1][j] == 1) {
                    tmp += UF->size((i - 1) * n+ j);
                    par.insert(UF->find((i - 1) * n+ j));
                }
                if(j > 0 && grid[i][j - 1] == 1) {
                    int x = UF->find(i * n + j - 1);
                    if(!par.count(x)) {
                        tmp += UF->size(i * n + j - 1);
                        par.insert(x);
                    }
                }

                if(i < (n - 1) && grid[i + 1][j] == 1) {
                    int x = UF->find((i + 1) * n + j);
                    if(!par.count(x)) {
                        tmp += UF->size((i + 1) * n + j);
                        par.insert(x);
                    }
                }

                if(j < (n - 1) && grid[i][j + 1] == 1) {
                    int x = UF->find((i) * n + j + 1);
                    if(!par.count(x)) {
                        tmp += UF->size((i) * n + j + 1);
                        par.insert(x);
                    }
                }
                mx = max(mx, 1 + tmp);
            }
        return ch? mx: n * n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/827.md" >}}
---
{{< youtube CIr-GvReMrw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #828: Count Unique Characters of All Substrings of a Given String](https://grid47.xyz/posts/leetcode_828) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

