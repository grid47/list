
+++
authors = ["Crafted by Me"]
title = "Leetcode 785: Is Graph Bipartite?"
date = "2022-09-09"
description = "In-depth solution and explanation for Leetcode 785: Is Graph Bipartite? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/785.md" >}}
---
{{< youtube j69Of_2nfRA >}}

| Next : [LeetCode #786: K-th Smallest Prime Fraction](grid47.xyz/leetcode_786) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

