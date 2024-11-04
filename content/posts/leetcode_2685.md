
+++
authors = ["Crafted by Me"]
title = "Leetcode 2685: Count the Number of Complete Components"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2685: Count the Number of Complete Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-complete-components/description/)

---

**Code:**

{{< highlight cpp >}}
class UF {
    public:
    vector<int> par, edge, rnk;
    UF(int n) {
        par.resize(n, 0);
        iota(par.begin(), par.end(), 0);
        edge.resize(n, 0);
        rnk.resize(n, 1);
    }
    
    bool join(int i, int j) {
        int p = find(i);
        int q = find(j);
        if(p != q) {
            if(rnk[p] > rnk[q]) {
                rnk[p]+=rnk[q];
                par[q] = p;
            } else {
                rnk[q]+=rnk[p];
                par[p] = q;         
            }
            int e = edge[p]+edge[q] + 1;
            edge[p] =e; // dge[q] + 1;
            edge[q] =e; // dge[p] + 1;            
            return true;
        }
        edge[q]++;
        return false;
    }
    int find(int p) {
        if(p == par[p]) return p;
        return par[p] = find(par[p]);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UF uf = UF(n);
        for(auto e: edges) {
            uf.join(e[0], e[1]);
        }
        set<int> pk;
        int res = 0;
            // cout << "edges membercnt edgescal \n";         
        for(int i = 0; i < n; i++) {
            int par = uf.find(i);
            if(pk.count(par)) continue;
            pk.insert(par);
            int cnt = uf.edge[par];
            // cout << cnt << " " << uf.rnk[par] << " " << uf.rnk[par] * (uf.rnk[par] - 1) / 2 << "\n";
            if(uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube J43LjwWYch4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2686: Immediate Food Delivery III](https://grid47.xyz/posts/leetcode_2686) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

