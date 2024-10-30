
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1627: Graph Connectivity With Threshold"
date = "2020-05-18"
description = "Solution to Leetcode 1627"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/graph-connectivity-with-threshold/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class UF {
public:
    vector<int> node;
    UF(int n) {
        node.resize(n + 1);
        for(int i = 0; i < n + 1; i++)
            node[i] = i;
    }
    
    bool join(int x, int y) {
        int p = find(x);
        int q = find(y);
        if(p == q) return false;
        node[p] = q;
        return true;
    }
    
    int find(int x) {
        int p = node[x];
        if(p == x) return p;
        return node[x] = find(p);
    }
    
};

class Solution {
public:
    vector<bool> areConnected(int n, int thq, vector<vector<int>>& q) {
        vector<bool> ans(q.size(), false);
        UF* uf = new UF(n);
        for(int i = thq + 1; i < n + 1; i++) {
            int m = 1;
            while(i * m <= n) {
                uf->join(i, i * m++);                
            }
        }

        for(int i = 0; i < q.size(); i++)
            ans[i] = uf->find(q[i][0]) == uf->find(q[i][1]);
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

