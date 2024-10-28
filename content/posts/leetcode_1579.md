
+++
authors = ["Yasir"]
title = "Leetcode 1579: Remove Max Number of Edges to Keep Graph Fully Traversable"
date = "2020-07-03"
description = "Solution to Leetcode 1579"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/)

---

**Code:**

{{< highlight html >}}
class UF {
    public:
    vector<int> a;
    int grp;
    UF(int n) {
        a.resize(n + 1);
        grp = n;
        iota(a.begin(), a.end(), 0);
    }
    
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p != q) {
            a[p] = q;
            grp--;
            return true;
        }
        return false;
    }
    bool conn(int x, int y) {
        return find(x) == find(y);
    }
    int find(int x) {
        return a[x] == x? x: (a[x] = find(a[x]));
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());
        UF a = UF(n), b = UF(n);
        int res = 0;
        for(int i = 0; i < edges.size(); i++) {
            if(edges[i][0] == 3) {
                if(!a.conn(edges[i][1], edges[i][2])) {
                    a.join(edges[i][1], edges[i][2]);
                    b.join(edges[i][1], edges[i][2]);
                } else res++;
            } else if(edges[i][0] == 1) {
                if(!a.conn(edges[i][1], edges[i][2])) {
                    a.join(edges[i][1], edges[i][2]);
                } else res++;
            } else if(edges[i][0] == 2) {
                if(!b.conn(edges[i][1], edges[i][2])) {
                    b.join(edges[i][1], edges[i][2]);
                } else res++;
            }
        }
        if(a.grp == 1 && b.grp == 1) return res;
        return -1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

