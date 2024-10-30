
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 547: Number of Provinces"
date = "2023-05-03"
description = "Solution to Leetcode 547"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-provinces/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class UnionFind {
    public:
        vector<int> par;
        int grp;
        UnionFind(int n) {
            par.resize(n);
            grp = n;
            for(int i = 0; i < n; i++)
                par[i] = i;
        }

        bool join(int i, int j) {
            int x = find(i);
            int y = find(j);
            if(x != y) {
                par[x] = y;
                grp--;
                return true;
            }
            return false;
        }

        int find(int x) {
            int y = par[x];
            return par[x] = x == y? x: find(y);
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        UnionFind* uf = new UnionFind(n);
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1) uf->join(i, j);
        
        return uf->grp;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/547.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

