
+++
authors = ["Yasir"]
title = "Leetcode 547: Number of Provinces"
date = "2023-04-29"
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

**Code:**

{{< highlight html >}}
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

