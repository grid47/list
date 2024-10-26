
+++
authors = ["Yasir"]
title = "Leetcode 785: Is Graph Bipartite?"
date = "2022-09-03"
description = "Solution to Leetcode 785"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/is-graph-bipartite/description/)

---

**Code:**

{{< highlight html >}}
class UF {
public:
    vector<int> chd;
    int cnt;
    
    UF(int n) {
        chd.resize(n, 0);
        for(int i = 0; i < n; i++)
            chd[i] = i;
        cnt = n;
    }
    
    bool uni(int x, int y) {
        int i = find(x);
        int j = find(y);
        if(i != j) {
            chd[i] = j;
            cnt--;
            return true;
        } else return false;
    }
    
    int find(int x) {
        if(x == chd[x]) return x;
        return chd[x] = find(chd[x]);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& gph) {
        int n = gph.size();
          UF* uf = new UF(n);

        for(int i = 0; i < n; i++) {
            for(int x: gph[i]) {
                if(uf->find(x) == uf->find(i)) return false;
                uf->uni(gph[i][0], x);
            }
        }
        return true;      
    }
};
{{< /highlight >}}

