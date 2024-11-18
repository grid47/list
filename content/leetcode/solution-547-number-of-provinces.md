
+++
authors = ["grid47"]
title = "Leetcode 547: Number of Provinces"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 547: Number of Provinces in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-provinces/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/547.webp" 
    alt="A map of regions where provinces are counted and highlighted, each province glowing softly."
    caption="Solution to LeetCode 547: Number of Provinces Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #553: Optimal Division](https://grid47.xyz/leetcode/solution-553-optimal-division/) |
| --- |
