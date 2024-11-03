
+++
authors = ["Crafted by Me"]
title = "Leetcode 1489: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree"
date = "2020-10-05"
description = "In-depth solution and explanation for Leetcode 1489: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/)

---

**Code:**

{{< highlight cpp >}}
class UnionFind {
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if (x == f[x]) return x;
        else return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if (rank[fx] == rank[fy]) rank[fy]++;
    }
    
private:
    vector<int> f, rank;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;
        for (int i = 0; i < edges.size(); ++i) {
            if (origin_mst < GetMST(n, edges, i)) {
                critical.push_back(edges[i][3]);
            } else if (origin_mst == GetMST(n, edges, -1, i)) {
                non_critical.push_back(edges[i][3]);
            }
        }
        return {critical, non_critical};
    }
    
private:
    int GetMST(const int n, const vector<vector<int>>& edges, int blockedge, int pre_edge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if (pre_edge != -1) {
            weight += edges[pre_edge][2];
            uf.Union(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == blockedge) continue;
            const auto& edge = edges[i];
            if (uf.Find(edge[0]) == uf.Find(edge[1])) continue;
            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; ++i) {
            if (uf.Find(i) != uf.Find(0)) return 1e9+7;
        }
        return weight;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1489.md" >}}
---


"| 1490: Clone N-ary Tree |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

