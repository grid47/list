
+++
authors = ["grid47"]
title = "Leetcode 1627: Graph Connectivity With Threshold"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1627: Graph Connectivity With Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Union Find","Number Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/graph-connectivity-with-threshold/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1627.md" >}}
---
{{< youtube cnZuX0TR9TQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1630: Arithmetic Subarrays](https://grid47.xyz/posts/leetcode-1630-arithmetic-subarrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
