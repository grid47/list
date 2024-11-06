
+++
authors = ["Crafted by Me"]
title = "Leetcode 547: Number of Provinces"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 547: Number of Provinces in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-provinces/description/)

---

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
---
{{< youtube p5Ocm71wB0E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #548: Split Array with Equal Sum](https://grid47.xyz/posts/leetcode_548) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
