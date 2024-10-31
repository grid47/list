
+++
authors = ["Crafted by Me"]
title = "Leetcode 928: Minimize Malware Spread II"
date = "2022-04-18"
description = "Solution to Leetcode 928"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-malware-spread-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par, rnk;
    UF(int n) {
        par.resize(n, 0);
        for(int i = 0; i < n; i++)
            par[i] = i;
        rnk.resize(n, 1);
    }
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p == q) return false;
        if(rnk[p] < rnk[q]) {
            par[p] = q;
            rnk[q] += rnk[p];
        } else {
            par[q] = p;
            rnk[p] += rnk[q];            
        }
        return true;
    }
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    int size(int x) {
        return rnk[find(x)];
    }
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& grid, vector<int>& mw) {
        int n = grid.size();        
        UF* uf = new UF(n);
        
        set<int> bad(mw.begin(), mw.end()), good;
        for(int i = 0; i < n; i++)
            if(!bad.count(i)) good.insert(i);
        
        for(int i : good)
        for(int j : good)
            if(i != j && grid[i][j]) uf->join(i, j);
        
        
        map<int, set<int>> mwg;
        map<int, int> deg;
        for(int m: bad) {
            for(int n: good)
                if(grid[m][n]) {
                    mwg[m].insert(uf->find(n));
                }
            for(int it: mwg[m])
            deg[it]++;
        }
        int node = mw[0], res = -1;
        // cout << mwg.size();
        for(auto mlw: mwg) {
            int cnt = 0;
            for(int g: mlw.second) {
                // cout << " " << g;
                if(deg[g] == 1)
                    cnt += uf->size(g);
            }
            if(cnt > res || (cnt == res && mlw.first < node)) {
                node = mlw.first;
                res = cnt;
            }
        }
        
        return node;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/928.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

